t=int(input())
for i in range(t):
    a=int(input())
    ans=1
    for j in range(1,a+1):
        if j%2:
            ans*=2
        else:
            ans+=1
    print(ans)
