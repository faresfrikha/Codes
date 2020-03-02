ch=input()
t=True
n=ch.count(ch[0])
s=set()
for x in ch:
    s.add(x)
for i in s:
    if n!=ch.count(i):
        t=False
        break
if t:
    print("YES")
else:
    print("NO")
