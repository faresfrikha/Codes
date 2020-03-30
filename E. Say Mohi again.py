n=int(input())
l=list(map(int,input().split()))
m=list(map(int,input().split()))
l=l[1:]
m=m[1:]
l=l+m
for i in range(1,n+1):
    if i not in l:
        print("You are not my boi")
        exit()
print("Hallelujah")
