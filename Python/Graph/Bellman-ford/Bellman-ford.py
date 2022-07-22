def bellman_ford(start):
    global dist, edge

    is_cycle = False
    dist = [INF for _ in range(n + 1)]
    dist[start] = 0

    # repeat multiple rounds to determine if a negative cycle exists
    for round in range(m):
        updated = False

        for e in edge:
            src, dst, weight = e
            if dist[src] is not INF and dist[src] + weight < dist[dst]:
                dist[dst] = dist[src] + weight
                updated = True

                # m - 1 repeat means that the shortest path continues to be updated
                # there is a negative cycle
                if round == m - 1:
                    is_cycle = True

        if not updated:
            break

    return is_cycle


if __name__ == '__main__':
    INF = 0x3f3f3f3f3f3f3f3f

    tc = int(input())

    for i in range(tc):
        edge = []
        dist = []

        n, m = map(int, input().split())

        for _ in range(m):
            u, v, w = map(int, input().split())
            edge.append((u, v, w))

        negative_cycle = bellman_ford(1)

        if i == 0:
            print()

        print("test case: ", i + 1)
        if negative_cycle:
            print("negative cycle exists")

        else:
            for j in range(2, n + 1):
                print("dist[{}]: {}".format(j, dist[j]) if (dist[i] is not INF) else -1)
