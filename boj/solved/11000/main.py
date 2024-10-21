import sys

N = int(input())
events = []
for _ in range(N):
    s, e = map(int, sys.stdin.readline().split())
    events.append((s, 1))
    events.append((e, -1))
events.sort(key = lambda x : (x[0], x[1]))
cur_room_cnt = 0
max_room_cnt = 0
for event in events:
    x, balance = event
    cur_room_cnt += balance
    max_room_cnt = max(max_room_cnt, cur_room_cnt)
print(max_room_cnt)