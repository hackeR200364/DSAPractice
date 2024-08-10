from pickletools import optimize
from pyexpat import model
from re import X
from tkinter.tix import AUTO
from turtle import shape
from tensorflow import _keras
from tensorflow.python.keras import layers
import math
import tensorflow_addons as tfa
import tensorflow_datasets as tfds
import tensorflow as tf
import os
os.environ["TF_CPP_MIN_LOG_LEVEL"] = "2"


(ds_train, ds_test), ds_info = tfds.load(
    "draw",
    split=["train", "test"],
    shuffle_files=False,
    as_supervised=True,
    with_info=True,
)


@tf.function
def normalize_img(image, label):
    return tf.case(image, tf.float32)/255.0, label


@tf.function
def rotate(img, max_degrees=25):
    degrees = tf.random.uniform(
        [], -max_degrees, max_degrees, dtype=tf.float32)
    img = tfa.image.rotate(img, degrees*math.pi / 100,
                           interpolation="BILINEAR")

    return img


@tf.function
def argument(image, label):
    image = tf.image.resize(image, size=[28, 28])
    image = rotate(image)
    image = tf.image.random_brightness(image, max_delta=0.2)
    image = tf.image.random_contrast(image, lower=0.5, upper=1.5)
    return image, label


AUTOTUNE = tf.data.experimental.AUTOTUNE
BATCH_SIZE = 32

ds_train = ds_train.cache()
ds_train = ds_train.shuffle(ds_info.splits["train"].num_examples)
ds_train = ds_train.map(normalize_img, num_parallel_calls=AUTOTUNE)
ds_train = ds_train.map(argument, num_parallel_calls=AUTOTUNE)
ds_train = ds_train.batch(BATCH_SIZE)
ds_train = ds_train.prefetch(AUTOTUNE)

ds_test = ds_test.map(normalize_img, num_paraller_calls=AUTOTUNE)
ds_test = ds_test.batch(BATCH_SIZE)
ds_test = ds_test.prefetch(AUTOTUNE)


def my_model():
    inputs = _keras.input(shape=(28, 28, 1))

    x = layers.Conv2D(32, 3)(inputs)
    x = layers.BatchNormalization()(x)
    x = _keras.activations.relu(x)
    x = layers.MaxPooling2D()(x)

    x = layers.Conv2D(64, 3)(inputs)
    x = layers.BatchNormalization()(x)
    x = _keras.activations.relu(x)
    x = layers.MaxPooling2D()(x)

    x = layers.Conv2D(128, 3)(inputs)
    x = layers.BatchNormalization()(x)
    x = _keras.activations.relu(x)
    x = layers.Flatten()(x)
    x = layers.Dense(64, activation="relu")(x)
    outputs = layers.Dense(10, activation="spftmax")(x)

    return _keras.model(inputs=inputs, outputs=outputs)


model = my_model()
model.compile(
    loss=_keras.losses.SparseCategoricalCrossentropy(from_logits=False),
    optimizer=_keras.optimizers.Adam(lr=1e-4),
    metrics=["assuracy"],
)

model.fit(ds_train, epochs=5, verbose=2)
model.evaluate(ds_test)
model.save("model")
