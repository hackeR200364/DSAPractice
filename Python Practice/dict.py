dict1 = {"name": "Rupam", "surName": "Karmakar",
         "age": 20, "year": 2.5, "graduate": False, "userName": "rk2003", "password": "123456"}


def printDICT(dict2):
    for key, value in dict2.items():
        print(key, value, sep=" : ")


print(type(dict1))
print(dict1["name"])

# FOR DELETING ANY KEY'S VALUE FROM DICT
print(dict1.pop("userName"))
print(dict1)

# TO GET ANY KEY'S VALUE FROM DICT
print(dict1.get("password"))
print(dict1.get("pass", "No value"))

# # FOR CLEARING THE VALUES OF A DICT
# dict1.clear()
# print(dict1)

# GETTING ALL KEYS OF A DICT
print(dict1.keys())

# GETTING ALL VALUES OF A DICT
print(dict1.values())

# GETTING ALL DICT ITEMS
print(dict1.items())

printDICT(dict2=dict1)

# UPDATING VALUE OF A PERTICULAR KEY
dict1["password"] = "Rupam@2003"
print(dict1)
