import sys

input = sys.stdin.readline
def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)

T = 1
for _ in range(T):
    a, b = map(int, input().split())
    x, y = a // b, a % b
    if y < 0:
        x += 1
        y -= b
    print(x, y, sep='\n')

