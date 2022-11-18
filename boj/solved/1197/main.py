import sys

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

class DSU:
    def __init__(self, n):
        self.p = [i for i in range(n)]

    def get(self, x):
        r = x
        while r != self.p[r]:
            r = self.p[r]
        while x != r:
            pr = self.p[x]
            self.p[x] = r
            x = pr
        return r        

    def unite(self, x, y):
        x = self.get(x)
        y = self.get(y)
        if x != y:
            self.p[x] = y
            return True
        return False

def ints():
    return map(int, sys.stdin.readline().split())

def main():
    n, m = ints()
    edges = [False] * m
    for i in range(m):
        x, y, w = ints()
        edges[i] = (x-1, y-1, w)
    edges.sort(key=lambda x: x[2])
    d = DSU(n)
    ans = 0
    for x, y, w in edges:
        if d.unite(x, y):
            ans += w
    print(ans)

if __name__ == '__main__':
    main()