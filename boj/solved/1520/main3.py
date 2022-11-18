import sys

input = sys.stdin.readline
def eprint(*args, **kwargs):print(*args, file=sys.stderr, **kwargs)
def strs(): return input().split()
def ints(): return map(int, input().split())

h, w = ints()
a = [list(ints()) for _ in range(h)]
g = [[] for _ in range(h * w)]
deg = [0] * (h * w)
for i in range(h):
    for j in range(w):
        v = i * w + j
        for ni, nj in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
            if 0 <= ni < h and 0 <= nj < w and a[ni][nj] < a[i][j]:
                u = ni * w + nj
                g[v].append(u)
                deg[u] += 1
que = []
for v in range(h * w):
    if deg[v] == 0:
        que.append(v)
dp = [0] * (h * w)
dp[0] = 1
for v in que:
    for u in g[v]:
        dp[u] += dp[v]
        deg[u] -= 1
        if deg[u] == 0:
            que.append(u)
print(dp[h * w - 1])