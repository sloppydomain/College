import heapq

# A* algorithm
# f(n) = g(n) + h(n)
# f(n) -> total cost
# g(n) -> distance from start

def a_star(n, e, edges, heuristics, start, end):
    adj = [[] for _ in range(n + 1)]
    for u, v, w in edges:
        adj[u].append((v, w))
        adj[v].append((u, w)) 

    M = float('inf')
    f = [M] * (n + 1)
    par = [-1] * (n + 1)
    pq = []
    heapq.heappush(pq, (heuristics[start], start))
    f[start] = heuristics[start]

    print("Traversal: ", end = " ")
    while pq:
        cost_u, u = heapq.heappop(pq)
        print(u, end = " ")
        if f[u] < cost_u:
            continue
        for v, w in adj[u]:
            new_cost = w + heuristics[v] + (f[u] - heuristics[u])
            if f[v] > new_cost:
                par[v] = u
                f[v] = new_cost
                heapq.heappush(pq, (f[v], v))

    path = []
    curr = end
    while curr != -1:
        path.append(curr)
        curr = par[curr]
    path.reverse()

    print("\nPath:", " -> ".join(map(str, path)))
    print("Cost:", f[end])

if __name__ == "__main__":
    n, e = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(e)]
    heuristics = [0] + list(map(int, input().split()))
    start, end = map(int, input().split())
    a_star(n, e, edges, heuristics, start, end)

'''
5 7
1 2 1
1 3 4
2 3 2
2 5 5
2 4 12
3 5 2
4 5 3
7 6 2 1 0
1 5
Traversal:  1 3 5 2 3 5 4 4 
Path: 1 -> 2 -> 3 -> 5
Cost: 5
'''