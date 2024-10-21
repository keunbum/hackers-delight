import sys

input = sys.stdin.readline
#def eprint(*args, **kwargs): print(*args, file=sys.stderr, **kwargs)

def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        A = list(map(int, input().split()))  
        B = list(map(int, input().split()))
        A.sort()
        B.sort()
        ans = 0
        j = 0
        for i in range(N):
            while j < M and B[j] < A[i]:
                j += 1
            ans += j
        print(ans)
    
if __name__ == '__main__':
    main()