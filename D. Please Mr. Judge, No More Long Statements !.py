n=int(input())
ch=input()
l=['a','o','y','e','u','i']
p=0
ans=0
for x in range(n):
    if ch[x] in l:
        ans=ans+x-p
        p+=1
print(ans)
