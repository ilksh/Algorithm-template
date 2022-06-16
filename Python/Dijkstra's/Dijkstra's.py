import heapq


def adj_check(u, v, w):
    global adj
    adj[u].append((w, v))


def fill_adj():
    # adj(node1, node2, weight)
    # the route from node1 to node2 takes as much time as weight
    adj_check(1, 2, 10)
    adj_check(1, 3, 20)
    adj_check(1, 4, 50)

    adj_check(2, 3, 7)
    adj_check(2, 4, 30)

    adj_check(3, 2, 8)
    adj_check(3, 4, 60)
    adj_check(3, 5, 43)

    adj_check(4, 5, 15)


def dijkstra(start):
    global time, heap, adj

    time[start] = 0
    heapq.heappush(heap, (0, start))

    while heap:
        cur_w, cur_node = heapq.heappop(heap)

        # do not search unnecessary node
        if time[cur_node] < cur_w:
            continue

        # search all nodes which are connected to the current node
        for edge in adj[cur_node]:
            # edge = (weight, node)
            next_w, next_node = edge
            next_w += cur_w
            # if the cost of new route is lower than that of current
            if next_w < time[next_node]:
                # update information
                time[next_node] = next_w
                heapq.heappush(heap, (next_w, next_node))


if __name__ == '__main__':
    INF = int(1e9)

    # The minimum cost to the ith node is time[i]
    time = [INF for _ in range(10)]

    heap = []   # Priority Queue
    adj = {}    # adjacency list

    for i in range(10):
        adj[i+1] = []

    fill_adj()
    dijkstra(1)

    for i in range(1, 6):
        print("{} : {}".format(i, time[i]))
    """
    1 : 0
    2 : 10
    3 : 17
    4 : 40
    5 : 55
    """