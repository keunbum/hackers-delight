# Prim Algorithm

input = __import__('sys').stdin.readline
def ints(): return map(int, input().split())

class Heap():
    def __init__(self, MAX_SIZE):
        self.MAX_SIZE = MAX_SIZE
        self.a = [None] * self.MAX_SIZE
        self.size = 0
        
    def push(self, x):
        assert self.size < self.MAX_SIZE
        self.a[self.size] = x
        self.size += 1
        i = self.size - 1
        p = (i - 1) // 2
        while i > 0 and self.a[p] > self.a[i]:
            self.a[i], self.a[p] = self.a[p], self.a[i]
            i = p
            p = (i - 1) // 2
    
    def top(self):
        return self.a[0]
        
    def pop(self):
        assert self.size > 0
        if self.size == 1:
            self.size -= 1
            return self.a[0]
        root = self.a[0]
        self.a[0] = self.a[self.size - 1]
        self.size -= 1
        self.heapify(0)
        return root
        
    def heapify(self, i):
        while True:
            l = i + i + 1
            r = l + 1
            mn = i
            if l < self.size and self.a[l] < self.a[mn]:
                mn = l
            if r < self.size and self.a[r] < self.a[mn]:
                mn = r
            if mn == i:
                break
            self.a[i], self.a[mn] = self.a[mn], self.a[i]
            i = mn

MAX_E = int(1e5)
n, m = ints()
g = [[] for _ in range(n)]
for _ in range(m):
    x, y, z = ints()
    x -= 1
    y -= 1
    g[x].append((y, z))
    g[y].append((x, z))
INF = int(1e6 + 1)
s = Heap(MAX_E + 1)
cost = [INF] * n
cost[0] = 0
s.push((cost[0], 0))
v_cnt = 0
ans = 0
while v_cnt < n:
    expected, v = s.top()
    s.pop()
    if expected != cost[v]:
        continue
    v_cnt += 1
    ans += cost[v]
    cost[v] = -INF
    for u, w in g[v]:
        if cost[u] > w:
            cost[u] = w
            s.push((cost[u], u))
print(ans)