fub=[0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025]
vou=['a','e','u','i','o']
n=int(input())
for i in range(n):
    ans=0
    ch=input()
    for x in ch:
        if x in vou:
            ans+=1;
    if ans in fub:
        print("Very cool name")
    else:
        print("meh")
