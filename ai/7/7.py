import sys
import heapq

'''
8 puzzle using best first search
'''

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    m = int(data[1])
    goal = "123456780"
    start = ""
    idx = 2
    for i in range(n):
        for j in range(m):
            start += data[idx]
            idx += 1
    if start == goal:
        print("0")
        return
    di = [-1, 1, 0, 0]
    dj = [0, 0, -1, 1]
    par = {start: "-1"}
    vis = {start}
    def h(s):
        d = 0
        for i in range(n * m):
            if s[i] != '0' and int(s[i]) != i + 1:
                d += 1
        return d
    pq = []
    heapq.heappush(pq, (h(start), start))
    ok = False
    while pq:
        f, curr = heapq.heappop(pq)
        if curr == goal:
            ok = True
            path = []
            p = curr
            while p != "-1":
                path.append(p)
                p = par[p]
            path.reverse()
            moves = ""
            for idx in range(len(path) - 1):
                p1 = path[idx].index('0')
                p2 = path[idx + 1].index('0')
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
            break
        pos = curr.index('0')
        i0, j0 = divmod(pos, m)
        for k in range(4):
            ni = i0 + di[k]
            nj = j0 + dj[k]
            if 0 <= ni < n and 0 <= nj < m:
                neig = list(curr)
                idx1 = i0 * m + j0
                idx2 = ni * m + nj
                neig[idx1], neig[idx2] = neig[idx2], neig[idx1]
                neig = "".join(neig)
                if neig not in vis:
                    par[neig] = curr
                    heapq.heappush(pq, (h(neig), neig))
                    vis.add(neig)
    if not ok:
        print("No solution")

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