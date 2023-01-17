list1 = ["FeedyTech", "The Bongo Riju"]

print(type(list1))

list2 = ["rupam", 7, 8, 20.03, True, "rupam"]

# PRINT IN A LIST FROM INDEX TO (REQUIRED INDEX + 1) //SLICING
print(list2[0:4])

# FOR SEEING HOW MANY TIMES A PARTICULAR VALUE HAVE IN A LIST
print(list2.count("rupam"))

# FOR SEEING THE INDEX OF A PARTICULAR VALUE
print(list2.index("rupam"))

# FOR SEEING THE INDEX OF A PARTICULAR VALUE IGNORING BEFORE OF A INDEX
print(list2.index("rupam", 1))

# TO INSERT IN A PERTICULAR INDEX IN A LIST
list2.insert(1, "karmakar")
print(list2)

# TO DELETE A PERTICULAR INDEXED VALUE FROM A LIST
list2.pop(2)
print(list2)

# TO DELETE LAST VALUE FROM A LIST
list2.pop()
print(list2)

# TO EXTEND A LIST TO ANOTHER LIST
list2.extend(list1)
print(list2)

# TO COPY ANY LIST'S ITEMS TO ANOTHER LIST
list3 = list2.copy()
print("list2=")
print(list2)
print("list3=")
print(list3)

list2.insert(1, "subscribe")

# TO COPY ANY LIST'S ITEMS TO ANOTHER LIST ANOTHER WAY
list3 = list2[:]
print("list2=")
print(list2)
print("list3=")
print(list3)

list2 = [7, 8, 1, 3, 10, 100, 30]

# TO SORT A LIST ASCENDING
list2.sort()
print(list2)

# TO SORT A LIST DESCENDING
list2.sort(reverse=True)
print(list2)

list2 = [7, 8, 1, 3, 10, 100, 30]

# TO REVERSE A LIST
list2.reverse()
print(list2)

# LIST COMPREHENSION
list2 = ["rupam", "karmakar", "FeddyTech",
         "The Bongo Riju", "Strange", "karmakar"]
a = [word for word in list2 if word.startswith("k")]
print(a)

# LIST UNPACKING
list2 = ["Rupam", "Karmakar"]
n1, n2 = list2
print(n1+" & "+n2)
