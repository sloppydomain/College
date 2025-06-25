from collections import deque

class State:
    def __init__(self, ml, cl, mr, cr, boat, parent=None):
        self.ml = ml
        self.cl = cl
        self.mr = mr
        self.cr = cr
        self.boat = boat
        self.parent = parent

    def is_valid(self):
        if self.ml < 0 or self.cl < 0 or self.mr < 0 or self.cr < 0:
            return False
        if self.ml > 3 or self.cl > 3 or self.mr > 3 or self.cr > 3:
            return False
        if (self.ml > 0 and self.ml < self.cl) or (self.mr > 0 and self.mr < self.cr):
            return False
        return True

    def is_goal(self):
        return self.ml == 0 and self.cl == 0 and self.mr == 3 and self.cr == 3 and not self.boat

    def possibilities(self):
        poss = []
        if self.boat:
            moves = [
                (2, 0), (0, 2), (1, 1), (1, 0), (0, 1)
            ]
            for m, c in moves:
                s = State(self.ml - m, self.cl - c, self.mr + m, self.cr + c, False, self)
                if s.is_valid():
                    poss.append(s)
        else:
            moves = [
                (2, 0), (0, 2), (1, 1), (1, 0), (0, 1)
            ]
            for m, c in moves:
                s = State(self.ml + m, self.cl + c, self.mr - m, self.cr - c, True, self)
                if s.is_valid():
                    poss.append(s)
        return poss

    def __eq__(self, other):
        return (self.ml, self.cl, self.mr, self.cr, self.boat) == (other.ml, other.cl, other.mr, other.cr, other.boat)

    def __hash__(self):
        return hash((self.ml, self.cl, self.mr, self.cr, self.boat))

def print_solution(state):
    if state is None:
        return
    print_solution(state.parent)
    print(f"({state.ml}, {state.cl}, {'left' if state.boat else 'right'}, {state.mr}, {state.cr})")

def solve_dfs(start):
    stack = [start]
    visited = set()
    visited.add(start)
    goal = None

    while stack:
        x = stack.pop()
        if x.is_goal():
            goal = x
            break
        for y in x.possibilities():
            if y not in visited:
                stack.append(y)
                visited.add(y)

    if goal:
        print("Yes")
        print_solution(goal)
    else:
        print("No")

if __name__ == "__main__":
    start = State(3, 3, 0, 0, True)
    solve_dfs(start)

'''
OUTPUT:
Yes
(3, 3, left, 0, 0)
(2, 2, right, 1, 1)
(3, 2, left, 0, 1)
(3, 0, right, 0, 3)
(3, 1, left, 0, 2)
(1, 1, right, 2, 2)
(2, 2, left, 1, 1)
(0, 2, right, 3, 1)
(0, 3, left, 3, 0)
(0, 1, right, 3, 2)
(0, 2, left, 3, 1)
(0, 0, right, 3, 3)
'''
