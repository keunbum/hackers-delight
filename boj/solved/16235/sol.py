import sys
from collections import deque

N, M, K = map(int, sys.stdin.readline().split())
# 
land = []
for _ in range(N):
    land.append([5] * N)

# 
A = []
for _ in range(N):
    A.append(list(map(int, sys.stdin.readline().split())))

# 
tree_info = [[deque() for _ in range(N)] for _ in range(N)]

for _ in range(M):
    r, c, age = map(int, sys.stdin.readline().split())
    tree_info[r - 1][c - 1].append(age)

for year in range(K):
    for r in range(N):
        for c in range(N):
            tree = deque()
            next_land = 0
            for age in tree_info[r][c]:
                if land[r][c] >= age:
                    land[r][c] -= age
                    tree.append(age + 1)
                else:
                    next_land += (age // 2)
            land[r][c] += next_land
            tree_info[r][c] = tree

    tmp_trees = [] # (r, c)
    for r in range(N):
        for c in range(N):
            for age in tree_info[r][c]:
                if age % 5 == 0: #
                    for i in range(-1, 2):
                        for j in range(-1, 2):
                            if not (i == j == 0) and 0 <= r + i < N and 0 <= c + j < N:
                                tmp_trees.append((r + i, c + j))
            land[r][c] += A[r][c]
    for pos in tmp_trees:
        r, c = pos
        tree_info[r][c].appendleft(1)

# 
ltree = 0
for r in range(N):
    for c in range(N):
        ltree += len(tree_info[r][c])
print(ltree)