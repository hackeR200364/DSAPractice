import math
while 1:
    n = int(input("Enter a Number = "))
    if n < 0:
        print("Square root cannot be calculated.")
        break
    else:
        if n != 998:
            print("Square root of ", n, "=", math.sqrt(n))
            continue
        else:
            break
