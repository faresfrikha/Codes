l=[]
l.append([[':',':',':'],[':','o',':'],[':',':',':']])
l.append([['o',':',':'],[':',':',':'],[':',':','o']])
l.append([[':',':','o'],[':','o',':'],['o',':',':']])
l.append([['o',':','o'],[':',':',':'],['o',':','o']])
l.append([['o',':','o'],[':','o',':'],['o',':','o']])
l.append([['o',':','o'],['o',':','o'],['o',':','o']])
l1=[]
l1.append([[':',':',':'],[':','o',':'],[':',':',':']])
l1.append([[':',':','o'],[':',':',':'],['o',':',':']])
l1.append([['o',':',':'],[':','o',':'],[':',':','o']])
l1.append([['o',':','o'],[':',':',':'],['o',':','o']])
l1.append([['o',':','o'],[':','o',':'],['o',':','o']])
l1.append([['o','o','o'],[':',':',':'],['o','o','o']])
m=[]
h1=[]
h2=[]
h3=[]
j=input()
for x in j:
    h1.append(x)
m.append(h1)
j=input()
for x in j:
    h2.append(x)
m.append(h2)
j=input()
for x in j:
    h3.append(x)
m.append(h3)
if m in l:
    print (l.index(m)+1)
elif m in l1:
    print (l1.index(m)+1)
else :
    print('unknown')
