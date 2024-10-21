import sys
input = sys.stdin.readline

n = int(input())
ok = True
a = [list(map(int, input().split())) for _ in range(n)]
used = n * n * [False]
for row in a:
    for x in row:
        ok &= not used[x - 1]
        used[x - 1] = True
ok &= (sorted([x for row in a for x in row]) == list(range(1, n * n + 1)))
target_sum = n * (n * n + 1) // 2
ok &= all(sum(row) == target_sum for row in a)
ok &= all(sum(col) == target_sum for col in zip(*a))
ok &= (sum(a[i][i] for i in range(n)) == target_sum)
ok &= (sum(a[i][~i] for i in range(n)) == target_sum)
print(['FALSE', 'TRUE'][ok])
