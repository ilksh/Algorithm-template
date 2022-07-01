import sys
import heapq
input = sys.stdin.readline


def route_print(r, terminal):
    print("route: ", end="")
    for elem in r[terminal]:
        print(elem, end=" ")
    print()


# s = start, e = end
def dijkstra(s, e):
    global adj

    # Initialize
    heap = []
    dist = [INF for _ in range(n + 1)]
    route = [[] for _ in range(n + 1)]

    dist[s] = 0
    route[s].append(s)
    heapq.heappush(heap, (0, s))

    while heap:
        cur_weight, cur_node = heapq.heappop(heap)

        if dist[cur_node] < cur_weight:
            continue

        for edge in adj[cur_node]:
            next_weight, next_node = edge
            next_weight += cur_weight

            if next_weight < dist[next_node]:
                dist[next_node] = next_weight
                heapq.heappush(heap, (next_weight, next_node))
                route[next_node] = route[cur_node] + [next_node]

    print("\nnode{} ~ node{} = {}".format(s, e, dist[e]))
    route_print(route, e)


if __name__ == '__main__':
    INF = int(1e9)

    n = int(input())    # number of node (vertex)
    m = int(input())    # number of edge

    adj = {}            # adjacency list
    for i in range(n + 1):
        adj[i] = []

    # {1: [(10, 2), (5, 3)], 2: [(4, 3),,,, (7, 4)], 7: [(8, 9)], 8: [], 9: []}
    for _ in range(m):
        node1, node2, weight = map(int, input().split())
        adj[node1].append((weight, node2))

    # find the shortest path from start to end
    for _ in range(3):
        start, end = map(int, input().split())
        dijkstra(start, end)

"""
9
14
1 2 10
1 3 5
2 3 4
2 4 7
3 2 4
3 5 19
3 7 24
4 5 4
4 7 15 
5 6 4
5 8 11
6 7 8
6 8 5 
7 9 8
1 2
2 9
3 8
"""

"""
result
====
node1 ~ node2 = 9
route: 1 3 2 

node2 ~ node9 = 30
route: 2 4 7 9 

node3 ~ node8 = 24
route: 3 2 4 5 6 8 
"""
