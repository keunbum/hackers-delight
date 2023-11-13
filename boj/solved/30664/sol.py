import sys

input = sys.stdin.readline
def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)
def strs(): return input().split()
def ints(): return map(int, input().split())

while True:
    n = int(input())
    if n == 0:
        break
    print('PREMIADO' if n % 42 == 0 else 'TENTE NOVAMENTE')