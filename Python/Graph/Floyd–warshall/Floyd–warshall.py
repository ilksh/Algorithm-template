def floyd_warshall():
    global dist

    for transit in range(1, n+1):
        for src in range(1, n+1):
            for dst in range(1, n+1):
                if src == dst:
                    continue
                dist[src][dst] = min(dist[src][dst], dist[src][transit] + dist[transit][dst])

    for src in range(1, n+1):
        for dst in range(1, n+1):
            print(dist[src][dst] if (dist[src][dst] is not INF) else 0, end=" ")
        print()


if __name__ == '__main__':
    INF = 0x3f3f3f3f

    n = int(input())
    m = int(input())

    dist = [[INF]*(n+1) for _ in range(n+1)]

    for _ in range(m):
        u, v, w = map(int, input().split())
        dist[u][v] = min(dist[u][v], w)

    # Unlike dijkstra's, floyd_warshall has no fixed start point.
    # Floyd_warshall finds the shortest routes between every pair of vertices.
    floyd_warshall()