import sys

input = sys.stdin.readline
#def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)

def main():
    h, w = map(int, input().split())
    s = [input().replace('.', 'D') for _ in range(h)]
    ok = True
    for i in range(h):
        for j in range(w):
            if j + 1 < w:
                ok &= s[i][j] != 'S' or s[i][j + 1] != 'W'
                ok &= s[i][j] != 'W' or s[i][j + 1] != 'S'
            if i + 1 < h:
                ok &= s[i][j] != 'S' or s[i + 1][j] != 'W'
                ok &= s[i][j] != 'W' or s[i + 1][j] != 'S'
    if ok:
        print(1)
        print(''.join(s))
    else:
        print(0)
    
if __name__ == '__main__':
    main()