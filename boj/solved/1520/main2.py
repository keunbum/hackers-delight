import sys

input = sys.stdin.readline
def eprint(*args, **kwargs):print(*args, file=sys.stderr, **kwargs)
def strs(): return input().split()
def ints(): return map(int, input().split())

h, w = ints()
a = [list(ints()) for _ in range(h)]
order = sorted([i for i in range(h * w)], key=lambda x: a[x // w][x % w], reverse=True)
dp = [[0] * w for _ in range(h)]
dp[0][0] = 1
for x in order:
    i, j = x // w, x % w
    for ni, nj in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
        if 0 <= ni < h and 0 <= nj < w and a[ni][nj] < a[i][j]:
            dp[ni][nj] += dp[i][j]
print(dp[h-1][w-1]) 