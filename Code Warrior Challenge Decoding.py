t=int(input())
for j in range(t):
    x=input()
    n=len(x)
    y=x[0]
    if n%2==1:
       for i in range(1,n):
           if i%2==1:
              y=x[i]+y
           else:
              y+=x[i]
    else:
        for i in range(1,n):
            if i%2==1:
               y+=x[i]
            else:
              y=x[i]+y
    print(y)
