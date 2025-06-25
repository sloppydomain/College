from collections import deque
from math import gcd

def print_path(parent, current):
    if current == (0, 0):
        print("<0, 0>")
        return
    print_path(parent, parent[current])
    print(f"<{current[0]}, {current[1]}>")

def solve(x, y, p, l):
    q = deque([p])
    status = {(0, 0)}
    parent = {(0, 0): (-1, -1)}
    found = False
    while q:
        curr = q.popleft()
        a, b = curr
        states = set()
        
        if (a == l and b == 0) or (a == 0 and b == l):
            print("\nSolution found!...")
            print_path(parent, curr)
            found = True

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
            if state not in status:
                status.add(state)
                q.append(state)
                parent[state] = curr
    if found == False:
        print("Solution not found :(...")

def main():
    x = int(input("Enter size of jug1: "))
    y = int(input("Enter size of jug2: "))
    p = (0, 0)
    l = int(input("Enter the size required: "))
    
    if l > max(x, y) or l % gcd(x, y) != 0:
        print("Required size is invalid...")
        return
    
    solve(x, y, p, l)

if __name__ == "__main__":
    main()


'''
OUTPUT1:
Enter size of jug1: 5
Enter size of jug2: 3
Enter the size required: 4

Solution found!...
<0, 0>
<5, 0>
<2, 3>
<2, 0>
<0, 2>
<5, 2>
<4, 3>
<4, 0>


OUTPUT2:
Enter size of jug1: 5
Enter size of jug2: 4
Enter the size required: 2

Solution found!...
<0, 0>
<5, 0>
<1, 4>
<1, 0>
<0, 1>
<5, 1>
<2, 4>
<2, 0>

Solution found!...
<0, 0>
<5, 0>
<1, 4>
<1, 0>
<0, 1>
<5, 1>
<2, 4>
<2, 0>
<0, 2>


OUTPUT3:
Enter size of jug1: 4
Enter size of jug2: 2
Enter the size required: 3
Required size is invalid...


Conclusion - Water Jug problem using Breadth first search algorithm was successfully studied and implemented.
'''