import sys

input = sys.stdin.readline
def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)
def strs(): return input().split()
def ints(): return map(int, input().split())

sys.setrecursionlimit(10 ** 6)
h, w = ints()
a = [list(ints()) for _ in range(h)]
dp = [[-1] * w for _ in range(h)]
dp[h - 1][w - 1] = 1
def DFS(i, j):
    if dp[i][j] >= 0:
        return dp[i][j]
    ret = 0
    for di, dj in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        ni = i + di
        nj = j + dj
        if 0 <= ni < h and 0 <= nj < w and a[ni][nj] < a[i][j]:
            ret += DFS(ni, nj)
    dp[i][j] = ret
    return ret
print(DFS(0, 0))