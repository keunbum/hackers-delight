import sys
input = sys.stdin.readline
from typing import List


board = []


for i in range(int(input())):
  board.append(list(map(int, input().split(" "))))


def canWin(board: List[List[int]]) -> bool:
    # Find all Go eggs on the board
    go_eggs = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 2:
                go_eggs.append((i, j))
    
    # Check if there is only one Go egg left
    if len(go_eggs) == 1:
        return True
    
    # Try to jump each Go egg
    for egg in go_eggs:
        x, y = egg
        # Check all possible directions to jump
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (-1,-1), (1,-1), (-1, 1)]:
            new_x = x + dx * 2
            new_y = y + dy * 2
            mid_x = x + dx
            mid_y = y + dy
            
            # Check if the jump is valid
            if new_x >= 0 and new_x < len(board) and new_y >= 0 and new_y < len(board[0]) and board[mid_x][mid_y] == 2 and board[new_x][new_y] == 0:
                # Make the jump and update the board
                board[x][y] = 0
                board[mid_x][mid_y] = 0
                board[new_x][new_y] = 2
                
                # Recursively check if we can win from this state
                if canWin(board):
                    return True
                
                # Undo the jump to backtrack to previous state of the board 
                board[x][y] = 2 
                board[mid_x][mid_y] = 2 
                board[new_x][new_y] = 0
                
    return False


if canWin(board):
    print("Possible")
else:
    print("Impossible")