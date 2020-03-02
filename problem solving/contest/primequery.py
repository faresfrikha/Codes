def sieve(upperbound,bs):
    sieve_size=upperbound+1
    bs[0]=0
    bs[1]=0
    for i in range(2,sieve_size+1):
        if(bs[i]):
            for j in range(i*i,sieve_size+1,i):
                bs[j]=0

def update(x,val,tree,n):
    while(x<=n):
        tree[x]+=val
        x+=(x)&(-x)
def get(x,tree,n):
    to=0
    while(x>0):
        to+=tree[x]
        x-=(x)&(-x)
    return to

tree=[0 for i in range(1000005)]
a=[0 for i in range(1000005)]
bs=[1 for i in range(2000100)]
sieve(2000000,bs)
n,q=map(int,input().split())
a=list(map(int,input().split()))
for i in range(n):
    if(bs[a[i]]):
        update(i+1,1,tree,n)
for i in range(q):
    l=list(map(int,input().split()))
    if (l[0]==1):
        ans=get(l[2],tree,n)-get(l[1]-1,tree,n)
        print(ans)
    else:
        y=l[1]
        y-=1
        a[y]+=1
        if(bs[a[y]]!=bs[a[y]-1]):
            if(bs[a[y]]):
                update(y+1,1,tree,n)
            else:
                update(y+1,-1,tree,n)

