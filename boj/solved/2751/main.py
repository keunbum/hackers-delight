import sys

input = sys.stdin.readline
def eprint(*args, **kwargs):print(*args, file=sys.stderr, **kwargs)
def strs(): return input().split()
def ints(): return map(int, input().split())

def merge(a, st, mid, en):
    buf = a[st:mid]
    L = 0
    R = mid
    ptr = st
    while L < (mid - st) and R < en:
        if buf[L] < a[R]:
            a[ptr] = buf[L]
            L += 1
        else:
            a[ptr] = a[R]
            R += 1
        ptr += 1
    while L < (mid - st):
        a[ptr] = buf[L]
        L += 1
        ptr += 1

# [st, en)
def merge_sort(a, st, en):
    n = en - st
    if n <= 1:
        return
    mid = (st + en) // 2
    merge_sort(a, st, mid)
    merge_sort(a, mid, en)
    merge(a, st, mid, en)

n = int(input())
a = [int(input()) for _ in range(n)]
merge_sort(a, 0, n)
print(*a, sep='\n')
#print('\n'.join(map(str, a)))
