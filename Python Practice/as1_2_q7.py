ll = int(input("Enter Lower limit:"))
ul = int(input("Enter upper limit:"))
# c=0
m = 2
while (ll < ul):
    for n in range(1, m+1):
        a = (m*m)-(n*n)
        b = 2*m*n
        ll = (m*m)+(n*n)
        if (ll > ul):
            break
        if (a == 0 or b == 0 or ll == 0):
            break
        print(a, b, ll)
    m = m+1
