n,m,k=map(int,input().split())
d=[0 for i in range(1000005)]
for i in range(n):
    l = list(map(int,input().split()))
    cond=True
    for j in l:
        if j!=l[0]:
            cond=False
        d[j]+=1
    if cond:
        d[l[0]]-=1
d.sort()
d.reverse()
print(n*m-d[0]-d[1])
