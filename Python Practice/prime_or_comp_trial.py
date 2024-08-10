p=c=0
while True:
    n=int(input("Enter a number[-1 to exit]:"))
    if(n==-1):
        break
    flag=1
    if (n<=1):
        flag=0
    for i in range(2,(n//2)+1):
        if (n%i==0):
            flag=0
            break
    if (flag==1):
        p=p+1
    else:
        c=c+1
print("Number of prime numbers:",p)
print("Number of composite numbers:",c)
