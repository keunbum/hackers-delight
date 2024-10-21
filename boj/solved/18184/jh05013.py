n, k = map(int,input().split())
print("YES")
for i in range(2**n):
    if k == 2**n or (i>0 and (1<<(i.bit_length()-1))&k): print(i, end=' ')