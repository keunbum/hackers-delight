import sys

input = sys.stdin.readline
def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)
def strs(): return input().split()
def ints(): return map(int, input().split())

K, L = ints()
i = 2
ok = True
while i * i <= K and i < L:
    if K % i == 0:
        ok = False
        break
    i += 1
if ok:
    print('GOOD')
else:
    print('BAD', i)