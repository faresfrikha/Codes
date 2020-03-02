from math import *
ans=[0 for i in range(10005)]
pos=[0 for i in range(10005)]
troll=[0 for i in range(10005)]
n,q=map(int,input().split())
a=list(map(int,input().split()))
p=list(map(int,input().split()))
for i in range(n):
    if(pos[a[i]]==0):
        pos[a[i]]=i+1
for i in range(n):
    x=a[i]
    if(pos[x]-1!=i):
        ans[i]=ans[i-1]
    else:
        ans[i]=max(ans[i],ans[i-1])
        u=1
        while(u<=sqrt(x)):
            if(x%u):
                u+=1
                continue
            if(x/u==u):
                if(pos[u]!=0):
                    troll[pos[u]-1]+=1
                    if(pos[u]<=pos[x]):
                        ans[i]=max(ans[i],troll[pos[u]-1])
            else:
                z=u
                if(pos[z]!=0):
                    troll[pos[z]-1]+=1
                    if(pos[z]<=pos[x]):
                        ans[i]=max(ans[i],troll[pos[z]-1])
                z=x//u
                if(pos[z]!=0):
                    troll[pos[z]-1]+=1
                    if(pos[z]<=pos[x]):
                        ans[i]=max(ans[i],troll[pos[z]-1])
            u+=1
for i in (p):
    print(ans[i-1])
                        
