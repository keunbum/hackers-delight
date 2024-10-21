import queue
import sys


def btn_a(val):
    val += 1
    if val > 99999:
        return -1
    return val


def btn_b(val):
    if val == 0:
        return val

    val *= 2
    if val > 99999:
        return -1

    temp = str(val)
    return int(str(int(temp[0]) - 1) + temp[1:])


def bfs(start, goal, max_depth):
    q = queue.Queue()
    q.put((0, start))
    visit = [0 for _ in range(100000)]
    visit[start] = 1

    while not q.empty():
        depth, node_val, = q.get()

        if node_val == goal:
            return depth

        child_a = btn_a(node_val)
        child_b = btn_b(node_val)

        if depth < max_depth:
            if child_a != -1 and not visit[child_a]:
                q.put((depth + 1, child_a))
                visit[child_a] = 1
            if child_b != -1 and not visit[child_b]:
                q.put((depth + 1, child_b))
                visit[child_b] = 1

    return "ANG"


if __name__ == '__main__':
    N, T, G = map(int, sys.stdin.readline().split())
    print(bfs(N, G, T))