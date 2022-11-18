import sys

input = sys.stdin.readline
def eprint(*args, **kwargs):print(*args, file=sys.stderr, **kwargs)
def strs(): return input().split()
def ints(): return map(int, input().split())

h, w = ints()
a = [list(ints()) for _ in range(h)]
order = sorted([(i // w, i % w) for i in range(h * w)], key=lambda x: a[x[0]][x[1]], reverse=True)
dp = [[0] * w for _ in range(h)]
dp[0][0] = 1
for i, j in order:
    for ni, nj in [(i+1,j), (i,j+1), (i-1,j), (i,j-1)]:
        if 0 <= ni < h and 0 <= nj < w and a[ni][nj] < a[i][j]:
            dp[ni][nj] += dp[i][j]
print(dp[h-1][w-1]) 