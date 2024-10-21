num = ['130542', '13', '03642', '03612', '5361',
       '05612', '056124', '031', '0123456', '01356']
num = [sum(1<<int(c) for c in s) for s in num]
conv = dict(zip(num, range(10)))

while 1:
    s = input()
    if s == "BYE": break
    a, b = s.split("+")
    sa = ''
    sb = ''
    for i in range(0, len(a), 3):
        sa+= str(conv[int(a[i:i+3])])
    for i in range(0, len(b)-1, 3):
        sb+= str(conv[int(b[i:i+3])])
    sc = str(int(sa)+int(sb))
    print(s, end='')
    for c in sc:
        print("%03d"%num[int(c)], end='')
    print()