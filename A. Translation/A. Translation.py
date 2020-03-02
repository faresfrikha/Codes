ch=input()
sh=input()
if len(sh)!=len(ch):
    print("NO")
else:
    i=0
    while i<len(ch):
        if ch[i]!=sh[len(ch)-1-i]:
            print("NO")
            break
        i+=1
    if i == len(ch):
        print("YES")
