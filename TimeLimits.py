n,s = map(int,input().split())
l=list(map(int,input().split()))
h=max(l)
print(int((h*s+1000-1)/1000))

