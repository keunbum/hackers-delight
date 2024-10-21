from collections import deque
import sys
input = sys.stdin.readline

num = deque()
for i in range(int(input())):
    cmd = input() 
    if 'push' in cmd:
        num.append(cmd.split()[1])
    elif cmd == 'pop':
        if len(num) == 0:
            print(-1)
        else:
            print(num.popleft())
    elif cmd == 'size':
        print(len(num))
    elif cmd == 'empty':
        print(1) if len(num) == 0 else print(0)
    elif cmd == 'front':
        print(-1) if len(num) == 0 else print(num[0])
    elif cmd == 'back':
        print(-1) if len(num) == 0 else print(num[-1])