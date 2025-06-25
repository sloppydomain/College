from collections import deque
from math import gcd

def print_path(parent, current):
    if current == (0, 0):
        print("<0, 0>")
        return
    print_path(parent, parent[current])
    print(f"<{current[0]}, {current[1]}>")

def solve_dfs(x, y, p, l):
    stack = [p]  # Using list as stack for DFS
    visited = {p}
    parent = {p: (-1, -1)}
    
    while stack:
        curr = stack.pop()  # DFS: pop last element
        a, b = curr
        
        # Check if we have reached the goal
        if (a == l and b == 0) or (a == 0 and b == l):
            print("\nSolution found!...")
            print_path(parent, curr)
            return

        # Generate next states based on current jug values
        states = set()
        if a == 0 and b == 0:
            states.add((x, 0))
            states.add((0, y))
        elif a == 0:
            states.add((x, b))
            if b <= x:
                states.add((b, 0))
            else:
                states.add((x, b - x))
        elif b == 0:
            states.add((a, y))
            if a <= y:
                states.add((0, a))
            else:
                states.add((a - y, y))
        else:
            states.add((0, b))
            states.add((a, 0))
            if a < x:
                states.add((x, b))
            if b < y:
                states.add((a, y))
            ca = x - a
            if ca:
                if ca <= b:
                    states.add((x, b - ca))
                else:
                    states.add((a + b, 0))
            cb = y - b
            if cb:
                if cb <= a:
                    states.add((a - cb, y))
                else:
                    states.add((0, a + b))
        
        # Process all new states
        for state in states:
            if state not in visited:
                visited.add(state)
                parent[state] = curr
                stack.append(state)
    print("Solution not found :(...")

def main():
    x = int(input("Enter size of jug1: "))
    y = int(input("Enter size of jug2: "))
    p = (0, 0)
    l = int(input("Enter the size required: "))
    
    if l > max(x, y) or l % gcd(x, y) != 0:
        print("Required size is invalid...")
        return
    
    solve_dfs(x, y, p, l)

if __name__ == "__main__":
    main()
