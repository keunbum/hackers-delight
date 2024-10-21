import sys
from collections import deque

N, L, R = map(int, sys.stdin.readline().split())
countries = []
for _ in range(N):
    countries.append(list(map(int, sys.stdin.readline().split())))

def bfs(start_r, start_c):
    global changed
    open_countries = [(start_r, start_c)]
    population = countries[start_r][start_c]
    q = deque()
    q.append((start_r, start_c))
    visited[start_r][start_c] = True
    while q:
        r, c = q.popleft()
        for dr, dc in ([(1, 0), (0, 1), (-1, 0), (0, -1)]):
            nr = r + dr
            nc = c + dc
            if min(nr, nc) < 0 or max(nr, nc) >= N or visited[nr][nc]:
                continue
            d = abs(countries[nr][nc] - countries[r][c])
            if d < L or d > R:
                continue
            visited[nr][nc] = True
            open_countries.append((nr, nc))
            population += countries[nr][nc]
            q.append((nr, nc))
    if len(open_countries) >= 2:
        changed = True
        mix(open_countries, population)

def mix(open_countries, population):
    new_population = population // len(open_countries)
    for country in open_countries:
        countries[country[0]][country[1]] = new_population

day = 0
changed = True
while changed:
    changed = False
    visited = []
    for _ in range(N):
        visited.append(list([False] * N))
    for r in range(N):
        for c in range(N):
            if not visited[r][c]:
                bfs(r, c)
    if changed:
        day += 1
print(day)