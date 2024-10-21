def solution(n, board, position):
    h = len(board)
    w = len(board[0])
    def solve(i, j):
        cnt = 0
        for di in [-1, 0, 1]:
            for dj in [-1, 0, 1]:
                ni, nj = i+di, j+dj
                cnt += (di or dj) and 0 <= ni < h and 0 <= nj < w and board[ni][nj]
        return (board[i][j] and 2 < cnt < 5) or (not board[i][j] and cnt == 2)
    return [int(solve(a, b)) for a, b in position]