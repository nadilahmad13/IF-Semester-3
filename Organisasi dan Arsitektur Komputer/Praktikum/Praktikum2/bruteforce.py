def func4(x,y):
    if (y < x):
        y = func4(y,x)
    elif (x != 0):
        y = func4(y % x,x)
    return y

x = 1
y = 1
found = True
while (found):
    print(x,y)
    iVar1 = func4(x,y)
    print(iVar1)
    if ((x * y) / iVar1) == 7:
        print("FOUND : ",x,y)
        found = False
    x = x + 1
    if (x == 10):
        x = 1
        y = y + 1