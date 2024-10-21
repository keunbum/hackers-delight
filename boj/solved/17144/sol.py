import sys
import time

#start = time.time()

R, C, T = map(int, sys.stdin.readline().split())
origin_matrix = []
for _ in range(R):
    origin_matrix.append(list(map(int, sys.stdin.readline().split())))

air_cleaner = []  # x 좌표만 저장

for r in range(R):
    for c in range(C):
        if origin_matrix[r][c] == -1:
            air_cleaner.append(r)

for _ in range(T):
    # <diffusion>
    new_matrix = [row[:] for row in origin_matrix] # 리스트 슬라이싱을 이용한 깊은 복사
    for i in range(R):
        for j in range(C):
            dust = origin_matrix[i][j]
            if dust == -1:
                continue
            for pos in [(i + 1, j), (i, j + 1), (i - 1, j), (i, j - 1)]:
                ni, nj = pos
                if 0 <= ni < R and 0 <= nj < C and origin_matrix[ni][nj] != -1:
                    cust = dust // 5
                    new_matrix[ni][nj] += cust;
                    new_matrix[i][j] -= cust;

    # 새 matrix로 바꾸는 식들인데 큰 차이는 없는 것 같네요.
#    origin_matrix = new_matrix
#    origin_matrix = new_matrix.copy()
    origin_matrix, new_matrix = new_matrix, origin_matrix

    # <move>
    # counterclockwise: start at air_cleaner[0]
    # 1) left
    for x in range(air_cleaner[0] - 2, -1, -1):
        origin_matrix[x + 1][0] = origin_matrix[x][0]
    # 2) up
    for y in range(1, C):
        origin_matrix[0][y - 1] = origin_matrix[0][y]
    # 3) right
    for x in range(1, air_cleaner[0] + 1):
        origin_matrix[x - 1][C - 1] = origin_matrix[x][C - 1]
    # 4) down
    for y in range(C - 2, 0, -1):
        origin_matrix[air_cleaner[0]][y + 1] = origin_matrix[air_cleaner[0]][y]
    origin_matrix[air_cleaner[0]][1] = 0  # 젤 마지막 0 채우기

    # clockwise: start at air_cleaner[1]
    # 1) left
    for x in range(air_cleaner[1] + 2, R):
        origin_matrix[x - 1][0] = origin_matrix[x][0]
    # 2) down
    for y in range(1, C):
        origin_matrix[R - 1][y - 1] = origin_matrix[R - 1][y]
    # 3) right
    for x in range(R - 2, air_cleaner[1] - 1, -1):
        origin_matrix[x + 1][C - 1] = origin_matrix[x][C - 1]
    # 4) up
    for y in range(C - 2, 0, -1):
        origin_matrix[air_cleaner[1]][y + 1] = origin_matrix[air_cleaner[1]][y]
    origin_matrix[air_cleaner[1]][1] = 0  # 젤 마지막 0 채우기

dust_sum = 2 #공기청정기 있는 칸이 -1씩 이므로
for row in origin_matrix:
    dust_sum += sum(row)
print(dust_sum)

#print(time.time() - start, "sec")