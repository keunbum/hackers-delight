import sys

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def solution(serial):
    ret = []
    s = 0
    for i in range(4):
        v = int(serial[i+i:i+i+2])
        if i < 3:
            s += v // 10 + v % 10
        if i == 0:
            ret.append(['male', 'female'][v-1])
        elif i == 1:
            ret.append(['operation', 'salse', 'develop', 'finance', 'law', 'research'][v%10])
        elif i == 2:
            ret.append(str(v) + 'team')
        else:
            ret.append('valid' if s%13 == v else 'invalid')
    return '/'.join(ret)
            
print(solution("01100103"))