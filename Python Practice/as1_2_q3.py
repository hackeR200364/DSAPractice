num = int(input("Enter the number : "))
p = c = 0
while num:
    num = int(input("Enter the number : "))
    if num % 2 == 0:
        p += 1
    else:
        c += 1

    if num == -1:
        print("Number of prime numbers : ", p)
        print("Number of composite numbers : ", c)
        break
