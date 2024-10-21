import sys
input = sys.stdin.readline
from typing import List, Tuple
from collections import deque


board = []


for i in range(int(input())):
  board.append(list(map(int, input().split(" "))))


def canWin(board: List[List[int]]) -> bool:
    go_eggs = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 2:
                go_eggs.append((i, j))
    if len(go_eggs) == 1:
        return True
    queue = deque()
    queue.append((board, go_eggs))
    while queue:
        current_board, current_go_eggs = queue.popleft()
        for egg in current_go_eggs:
            x, y = egg
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (-1,-1), (1,-1), (-1, 1)]:
                new_x = x + dx * 2
                new_y = y + dy * 2
                mid_x = x + dx
                mid_y = y + dy
                if new_x >= 0 and new_x < len(current_board) and new_y >= 0 and new_y < len(current_board[0]) and current_board[mid_x][mid_y] == 2 and current_board[new_x][new_y] == 0:
                    new_board = [row[:] for row in current_board]
                    new_board[x][y] = 0 
                    new_board[mid_x][mid_y] = 0 
                    new_board[new_x][new_y] = 2 
                    new_go_eggs = current_go_eggs[:]
                    new_go_eggs.remove(egg)
                    new_go_eggs.remove((mid_x,mid_y))
                    new_go_eggs.append((new_x,new_y))
                    if len(new_go_eggs) == 1: 
                        return True
                    queue.append((new_board,new_go_eggs)) 
    return False


if canWin(board):
    print("Possible")
else:
    print("Impossible")

