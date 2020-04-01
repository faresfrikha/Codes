ch=input()
a=0
for i in range(len(ch)):
    a+=ord(ch[i])-65-2*(ord(ch[i])-65)*((1+ord(ch[i]))%2)
    #print(a)
print(a)
