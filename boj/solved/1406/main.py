import sys

raw_string = list(input())
n = int(input())
cursor = len(raw_string)

for _ in range(n):
    command = sys.stdin.readline().rstrip()
    if command == 'L':
        if cursor:
            cursor -= 1
    elif command == 'D':
        if cursor != len(raw_string):
            cursor += 1
    elif command == 'B':
        if cursor:
            if cursor == len(raw_string):
                raw_string.pop()
            else:
                raw_string = raw_string[0:cursor - 1] + raw_string[cursor:5]
            cursor -= 1
    else:
        command, chr = command.split()
        if cursor == len(raw_string):
            raw_string.append(chr)
        else:
            tmp = raw_string[0:cursor]
            tmp.append(chr)
            raw_string = tmp + raw_string[cursor:5]
        cursor += 1

print(''.join(raw_string))