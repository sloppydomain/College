from collections import deque

def print_path(parent, current):
    if current == (0, 0):
        print("<0, 0>")
        return
    print_path(parent, parent[current])
    print(f"<{current[0]}, {current[1]}>")

def solve(x, y, p, l):
    q = deque([p])
    visited = {(0, 0)}
    parent = {(0, 0): (-1, -1)}
    
    while q:
        curr = q.popleft()
        a, b = curr
        states = set()

        if (a == l and b == 0) or (a == 0 and b == l):
            print("Solution found!...")
            print_path(parent, curr)
            return
        
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
        
        for state in states:
            if state not in visited:
                visited.add(state)
                q.append(state)
                parent[state] = curr
                
    print("Solution not found :(...")

def main():
    x = int(input("Enter size of jug1: "))
    y = int(input("Enter size of jug2: "))
    p = (0, 0)
    l = int(input("Enter the size required: "))
    
    if l > max(x, y):
        print("Required size is invalid...")
        return
    
    solve(x, y, p, l)

if __name__ == "__main__":
    main()
