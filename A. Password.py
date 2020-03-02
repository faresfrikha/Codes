ch=input()
n=len(ch)
ans=""
for i in range(1,len(ch)-1):
    pre=ch[:i]
    #print(pre)
    suf=ch[n-i:]
    #print(suf)
    if pre!=suf:
        continue
    pos=ch[1:n-1].count(pre)
    if pos>0:
        ans=pre
if len(ans)>0:
    print(ans)
else:
    print("Just a legend")
