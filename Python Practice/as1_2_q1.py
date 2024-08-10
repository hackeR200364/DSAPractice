r = int(input("Enter the number of rows:"))
c = 0
for i in range(0, r+1):
    for j in range(i):
        print(c, end=" ")
        c = c+1
    print('')
