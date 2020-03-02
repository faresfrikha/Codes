n,k=map(int,input().split())
a=list(map(int,input().split()))
j=0
ans=0
res=0
for i in range(n):
    res+=a[i]
    while(res>k):
        res-=a[j]
        j+=1
    ans=max((ans,i-j+1))
print(n-ans)
