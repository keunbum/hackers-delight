import sys

N = int(input())
a = []
for _ in range(N):
    s, e = map(int, sys.stdin.readline().split())
    a.append((s, e))
a.sort(key = lambda x : (x[0], x[1]))
