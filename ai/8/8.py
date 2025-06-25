'''
steepest descent (greedy hill climbing)
'''
def main():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    it = iter(input_data)
    n = int(next(it))
    e = int(next(it))
    g = [[] for _ in range(n + 1)]
    for _ in range(e):
        u = int(next(it))
        v = int(next(it))
        g[u].append(v)
        g[v].append(u)
    h = [0] * (n + 1)
    for i in range(1, n + 1):
        h[i] = int(next(it))
    vis = [False] * (n + 1)
    start = int(next(it))
    w = h[start]
    vis[start] = True
    end = int(next(it))
    u = start
    p = [-1] * (n + 1)
    
    while True:
        par = u
        ok = False
        for v in g[u]:
            if not vis[v] and h[v] < w:
                w = h[v]
                u = v
                ok = True
        if not ok:
            print("No solution found...")
            print("Traversal: ", end="")
            path = []
            curr = u
            while curr != -1:
                path.append(curr)
                curr = p[curr]
            path.reverse()
            for a in path:
                print(a, end=" ")
            print()
            break
        vis[u] = True
        p[u] = par
        if u == end:
            print("Path found: ", end="")
            path = []
            curr = end
            while curr != -1:
                path.append(curr)
                curr = p[curr]
            path.reverse()
            for a in path:
                print(a, end=" ")
            print()
            break
if __name__ == '__main__':
    main()

'''
INPUT:
7 10
1 2
1 3
2 3
2 4
3 5
3 7
4 5
4 6
5 6
6 7
1 2 2 6 3 6 4
6 1

OUTPUT:
Path found: 6 5 3 1
'''