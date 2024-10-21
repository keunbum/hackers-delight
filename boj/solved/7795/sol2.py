import sys
from bisect import bisect_left

input = sys.stdin.readline
#def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)

def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        A = list(map(int, input().split()))  
        B = list(map(int, input().split()))
        B.sort()
        ans = 0
        for i in range(N):
            ans += bisect_left(B, A[i])
        print(ans)
    
if __name__ == '__main__':
    main()