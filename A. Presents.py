n=int(input())
l=list(map(int,input().split()))
s=[0]*n
for i in range (n):
    s[l[i]-1]+=i+1
for j in range (n):
    print(s[j],end=' ')
