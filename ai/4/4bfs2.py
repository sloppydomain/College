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
            s1 = State(self.ml - 2, self.cl, self.mr + 2, self.cr, False, self)
            if s1.is_valid(): poss.append(s1)
            s2 = State(self.ml, self.cl - 2, self.mr, self.cr + 2, False, self)
            if s2.is_valid(): poss.append(s2)
            s3 = State(self.ml - 1, self.cl - 1, self.mr + 1, self.cr + 1, False, self)
            if s3.is_valid(): poss.append(s3)
            s4 = State(self.ml - 1, self.cl, self.mr + 1, self.cr, False, self)
            if s4.is_valid(): poss.append(s4)
            s5 = State(self.ml, self.cl - 1, self.mr, self.cr + 1, False, self)
            if s5.is_valid(): poss.append(s5)
        else:
            s1 = State(self.ml + 2, self.cl, self.mr - 2, self.cr, True, self)
            if s1.is_valid(): poss.append(s1)
            s2 = State(self.ml, self.cl + 2, self.mr, self.cr - 2, True, self)
            if s2.is_valid(): poss.append(s2)
            s3 = State(self.ml + 1, self.cl + 1, self.mr - 1, self.cr - 1, True, self)
            if s3.is_valid(): poss.append(s3)
            s4 = State(self.ml + 1, self.cl, self.mr - 1, self.cr, True, self)
            if s4.is_valid(): poss.append(s4)
            s5 = State(self.ml, self.cl + 1, self.mr, self.cr - 1, True, self)
            if s5.is_valid(): poss.append(s5)
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

def solve(start):
    q = deque([start])
    visited = set()
    visited.add(start)
    goal = None

    while q:
        x = q.popleft()
        if x.is_goal():
            goal = x
            break
        for y in x.possibilities():
            if y not in visited:
                q.append(y)
                visited.add(y)

    if goal:
        print("Yes")
        print_solution(goal)
    else:
        print("No")

if __name__ == "__main__":
    start = State(3, 3, 0, 0, True)
    solve(start)