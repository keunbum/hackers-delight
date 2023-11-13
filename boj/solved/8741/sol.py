import sys

input = sys.stdin.readline
def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)
def strs(): return input().split()
def ints(): return map(int, input().split())

k = int(input())
n = 1 << k
print(bin(n * (n - 1) // 2)[2:])