import sys

input = sys.stdin.readline
#def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)

def main():
    n = int(input())
    a = list(map(int, input().split()))
    stk = []
    cnt = 0
    for x in a:
        while stk and stk[-1] < x:
            if cnt + 1 != stk[-1]:
                print("Sad")
                return
            cnt += 1
            stk.pop()
        stk.append(x)
    print("Nice")

if __name__ == '__main__':
    main()