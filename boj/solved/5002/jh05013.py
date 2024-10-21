lim = int(input())
s = input()

mansub = 0 # man minus woman
for i in range(len(s)):
    if s[i] == "M": mansub+= 1
    else: mansub-= 1
    if abs(mansub) >= lim+2:
        print(i-1)
        break
else:
    if abs(mansub) >= lim+1: print(i)
    else: print(i+1)