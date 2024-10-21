def place(i):
    if s != t[i:i+len(s)]: return False
    l = i-1
    r = i+len(s)
    switched = False
    for ci in range(len(t)-len(s)):
        if switched:
            if l == -1: return False
            if t[l] == "B": switched = False
            l-= 1
        else:
            if r == len(t): return False
            if t[r] == "B": switched = True
            r+= 1
    return True

s = input()
t = input()
if (t.count("B") - s.count("B")) % 2: t = t[::-1]
print(int(any(place(i) for i in range(len(t)-len(s)+1))))
