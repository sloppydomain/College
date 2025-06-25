import random

def calculate_conflicts(board, row, col):
    conflicts = 0
    n = len(board)
    for c in range(n):
        if c == col:
            continue
        r = board[c]
        if r == row or abs(r - row) == abs(c - col):
            conflicts += 1
    return conflicts

def get_total_heuristic(board):
    total = 0
    n = len(board)
    for col in range(n):
        total += calculate_conflicts(board, board[col], col)
    return total // 2

def get_conflicted_columns(board):
    conflicted = []
    n = len(board)
    for col in range(n):
        if calculate_conflicts(board, board[col], col) > 0:
            conflicted.append(col)
    return conflicted

def print_board(board, step):
    print(f"\nStep {step}:")
    n = len(board)
    for row in range(n):
        line = ""
        for col in range(n):
            if board[col] == row:
                line += " Q "
            else:
                line += " . "
        print(line)
    print("Heuristic (number of attacking pairs):", get_total_heuristic(board))
    print("-" * (4 * len(board)))

def min_conflicts(board, max_steps=100):
    n = len(board)
    for step in range(max_steps):
        print_board(board, step)
        conflicted = get_conflicted_columns(board)
        if not conflicted:
            print(f"\nSolution found in {step} steps.")
            return board

        col = random.choice(conflicted)
        min_conflict = calculate_conflicts(board, board[col], col)
        best_rows = []

        for row in range(n):
            conflicts = calculate_conflicts(board, row, col)
            if conflicts < min_conflict:
                min_conflict = conflicts
                best_rows = [row]
            elif conflicts == min_conflict:
                best_rows.append(row)

        board[col] = random.choice(best_rows)

    print("\nFailed to find a solution within the step limit.")
    return None

n = int(input("Enter the number of queens (N): "))
use_custom = input("Do you want to enter initial board? (y/n): ").lower()
if use_custom == 'y':
    board = list(map(int, input(f"Enter {n} row positions (space-separated): ").split()))
    if len(board) != n:
        print("Invalid input! Using random board instead.")
        board = [random.randint(0, n - 1) for _ in range(n)]
else:
    board = [random.randint(0, n - 1) for _ in range(n)]

solution = min_conflicts(board)
if solution:
    print_board(solution, "Final")
else:
    print("Try running again — solution not found in limit.")


'''
INPUT:
Enter the number of queens (N): 4
Do you want to enter initial board? (y/n): y 
Enter 4 row positions (space-separated): 0 1 2 3

OUTPUT:
Step 0:
 Q  .  .  . 
 .  Q  .  . 
 .  .  Q  . 
 .  .  .  Q 
Heuristic (number of attacking pairs): 6
----------------

Step 1:
 Q  Q  .  . 
 .  .  .  . 
 .  .  Q  . 
 .  .  .  Q 
Heuristic (number of attacking pairs): 4
----------------

Step 2:
 Q  Q  .  . 
 .  .  .  Q 
 .  .  Q  . 
 .  .  .  . 
Heuristic (number of attacking pairs): 3
----------------

Step 3:
 Q  .  .  . 
 .  .  .  Q 
 .  Q  Q  . 
 .  .  .  . 
Heuristic (number of attacking pairs): 3
----------------

Step 4:
 Q  .  .  . 
 .  .  .  Q 
 .  Q  Q  . 
 .  .  .  . 
Heuristic (number of attacking pairs): 3
----------------

Step 5:
 Q  .  .  . 
 .  .  .  Q 
 .  Q  Q  . 
 .  .  .  . 
Heuristic (number of attacking pairs): 3
----------------

Step 6:
 Q  .  .  . 
 .  .  .  Q 
 .  Q  Q  . 
 .  .  .  . 
Heuristic (number of attacking pairs): 3
----------------

Step 7:
 Q  Q  .  . 
 .  .  .  Q 
 .  .  Q  . 
 .  .  .  . 
Heuristic (number of attacking pairs): 3
----------------

Step 8:
 Q  Q  .  . 
 .  .  .  Q 
 .  .  .  . 
 .  .  Q  . 
Heuristic (number of attacking pairs): 1
----------------

Step 9:
 Q  .  .  . 
 .  .  .  Q 
 .  Q  .  . 
 .  .  Q  . 
Heuristic (number of attacking pairs): 1
----------------

Step 10:
 Q  .  .  . 
 .  .  .  Q 
 .  Q  .  . 
 .  .  Q  . 
Heuristic (number of attacking pairs): 1
----------------

Step 11:
 Q  Q  .  . 
 .  .  .  Q 
 .  .  .  . 
 .  .  Q  . 
Heuristic (number of attacking pairs): 1
----------------

Step 12:
 Q  .  .  . 
 .  .  .  Q 
 .  Q  .  . 
 .  .  Q  . 
Heuristic (number of attacking pairs): 1
----------------

Step 13:
 Q  Q  .  . 
 .  .  .  Q 
 .  .  .  . 
 .  .  Q  . 
Heuristic (number of attacking pairs): 1
----------------

Step 14:
 .  Q  .  . 
 .  .  .  Q 
 Q  .  .  . 
 .  .  Q  . 
Heuristic (number of attacking pairs): 0
----------------

Solution found in 14 steps.

Step Final:
 .  Q  .  . 
 .  .  .  Q 
 Q  .  .  . 
 .  .  Q  . 
Heuristic (number of attacking pairs): 0
----------------
'''