from queue import PriorityQueue
import sys

N = int(input())
classes = []
for _ in range(N):
    s, e = map(int, sys.stdin.readline().split())
    classes.append((s, e))

classes = sorted(classes, key = lambda x : (x[0], x[1]))
pq = PriorityQueue(maxsize=N)
for i in range(N):
    pq.put((i, classes[i]))

room_cnt = 0
while pq:
    room_cnt += 1
    nq = PriorityQueue(maxsize=N)
    ex = pq.get()[1]
    idx = 0
    for i in range(pq.qsize()):
        now = pq.get()[1]
        if now[0] >= ex[1]:
            ex = now
            continue
        else:
            nq.put((idx, now))
            idx += 1
    if nq.qsize() == 0:
        break
    pq = nq
print(room_cnt)