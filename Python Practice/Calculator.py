import math
print("----------CALCULATOR----------\n--Choose The Operation You Want To Perform--\n")
print("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square Root\n6. EXIT")

while True:
    ch = int(input("Enter what do you want to perform = "))
    if (ch == 1):
        print("---Performing Addition---")
        a = int(input("Enter 1st Number:"))
        b = int(input("Enter 2nd Number:"))
        c = a+b
        print(a, "+", b, "=", c)
    elif (ch == 2):
        print("---Performing Subtraction---")
        a = int(input("Enter 1st Number:"))
        b = int(input("Enter 2nd Number:"))
        c = a-b
        print(a, "-", b, "=", c)
    elif (ch == 3):
        print("---Performing Multiplication---")
        a = int(input("Enter 1st Number:"))
        b = int(input("Enter 2nd Number:"))
        c = a*b
        print(a, "×", b, "=", c)
    elif (ch == 4):
        print("---Performing Division---")
        a = int(input("Enter 1st Number:"))
        b = int(input("Enter 2nd Number:"))
        c = a/b
        print(a, "÷", b, "=", c)
    elif (ch == 5):
        print("---Square rooting---")
        a = int(input("Enter the Number:"))
        sqr = math.sqrt(a)
        print("√", a, "=", sqr)
    elif (ch == 6):
        break
    else:
        print("---INVALID CHOICE---")
