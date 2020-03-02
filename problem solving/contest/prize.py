n,a=map(int,input().split())
p=list(map(int,input().split()))
for i in p:
    x=i//a
    ans=x
    ans+=i%a
    print(ans)
