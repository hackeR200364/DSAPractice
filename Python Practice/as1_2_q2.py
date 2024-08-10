r = int(input("Enter the number of rows:"))
for i in range(1, r+1):
    num = 1
    for j in range(r+1, 0, -1):
        if j > i:
            print(" ", end=" ")
        else:
            print(num, end=" ")
            num += 1
    print("")
