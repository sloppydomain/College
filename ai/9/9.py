import sys
'''
8 puzzle using hill climbing
'''
def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    m = int(data[1])
    goal = "123456780"
    start = ""
    idx = 2
    for i in range(n * m):
        start += data[idx]
        idx += 1
    if start == goal:
        print("0")
        return
    def is_solvable(s):
        inv = 0
        for i in range(n * m):
            if s[i] == '0': continue
            for j in range(i + 1, n * m):
                if s[j] == '0': continue
                if s[i] > s[j]:
                    inv += 1
        return inv % 2 == 0
    def heuristic(s):
        h = 0
        for i in range(n * m):
            if s[i] != '0' and int(s[i]) != i + 1:
                h += 1
        return h
    if not is_solvable(start):
        print("No solution")
        return
    di = [-1, 1, 0, 0]
    dj = [0, 0, -1, 1]
    vis = {start}
    parent = {start: ""}
    curr = start
    solved = False
    while True:
        if curr == goal:
            solved = True
            break
        zp = curr.find('0')
        ci, cj = zp // m, zp % m
        currH = heuristic(curr)
        best = curr
        bestH = currH
        for k in range(4):
            ni = ci + di[k]
            nj = cj + dj[k]
            if ni < 0 or ni >= n or nj < 0 or nj >= m:
                continue
            nxt = list(curr)
            nxt[ci * m + cj], nxt[ni * m + nj] = nxt[ni * m + nj], nxt[ci * m + cj]
            nxt = "".join(nxt)
            if nxt in vis:
                continue
            hnext = heuristic(nxt)
            if hnext < bestH:
                bestH = hnext
                best = nxt
        if best == curr:
            break
        vis.add(best)
        parent[best] = curr
        curr = best
    if not solved:
        print("No path...")
    else:
        path = []
        s = goal
        while s:
            path.append(s)
            s = parent[s]
        path.reverse()
        moves = ""
        for i in range(len(path) - 1):
            p1 = path[i].find('0')
            p2 = path[i + 1].find('0')
            i1, j1 = divmod(p1, m)
            i2, j2 = divmod(p2, m)
            if i2 == i1 - 1:
                moves += 'U'
            elif i2 == i1 + 1:
                moves += 'D'
            elif j2 == j1 - 1:
                moves += 'L'
            elif j2 == j1 + 1:
                moves += 'R'
        print("Solution: " + moves)

if __name__ == '__main__':
    main()

'''
OUTPUT:
3 3
1 2 3 
4 0 6 
7 5 8
Solution: DR
'''