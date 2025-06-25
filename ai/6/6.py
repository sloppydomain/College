import heapq

def main():
    tt = int(input())
    for _ in range(tt):
        n, e = map(int, input().split())
        edges = [[] for _ in range(n)]
        for _ in range(e):
            u, v = map(int, input().split())
            edges[u].append(v)
            edges[v].append(u)
        h = list(map(int, input().split()))
        start, end = map(int, input().split())
        pq = []
        heapq.heappush(pq, (h[start], start))
        
        parent = [-1] * n
        visited = [False] * n
        visited[start] = True
        
        traversal = []
        found = False
        
        while pq:
            curr_h, curr = heapq.heappop(pq)
            traversal.append(curr)
            if curr == end:
                found = True
                break
            for neighbor in edges[curr]:
                if not visited[neighbor]:
                    heapq.heappush(pq, (h[neighbor], neighbor))
                    visited[neighbor] = True
                    parent[neighbor] = curr
        
        print("Traversal:", " ".join(map(str, traversal)))
        if not found:
            print("Path: No path found")
        else:
            path = []
            cur = end
            cost = 0
            while cur != -1:
                cost += h[cur]
                path.append(cur)
                cur = parent[cur]
            path.reverse()
            print("Path:", " ".join(map(str, path)))
            print("Total cost: ", cost)
            
if __name__ == "__main__":
    main()

'''
OUTPUT:
1
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
Traversal: 6 2 0 1 
Path: 6 2 1 
Total cost: 8
'''