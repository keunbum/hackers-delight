import sys

def make_mid_list(nums):
    result = []
    tmp = []
    cnt = 1
    for num in nums:
        tmp.append(num)
        if cnt % 2 == 1:
            tmp.sort()
            result.append(str(tmp[cnt // 2]))
        cnt += 1
    return result

t = int(input())
answer = []
cnt_list = []
for _ in range(t):
    n = int(sys.stdin.readline())
    if n % 2 == 0:
        cnt_list.append(n // 2)
    else:
        cnt_list.append(n // 2 + 1)

    if n > 10:
        n = n // 10
        for i in range(n // 2):
            nums1 = list(map(int, sys.stdin.readline().split()))
            nums2 = list(map(int, sys.stdin.readline().split()))
            answer.append(make_mid_list(nums1 + nums2))
        nums = list(map(int, sys.stdin.readline().split()))
        answer.append(make_mid_list(nums))
    else:
        nums = list(map(int, sys.stdin.readline().split()))
        answer.append(make_mid_list(nums))

tmp_cnt = 0
flag = 0
for mid_list in answer:
    if flag != 0:
        print(' '.join(mid_list))
        flag -= 1
    else:
        if cnt_list[tmp_cnt] < 10:
            print(cnt_list[tmp_cnt])
            print(' '.join(mid_list))
            tmp_cnt += 1
        elif cnt_list[tmp_cnt] > 10:
            print(cnt_list[tmp_cnt])
            print(' '.join(mid_list))
            flag = cnt_list[tmp_cnt] // 10
            tmp_cnt += 1