from collections import deque


# adjacency list
def adj_check(node1, node2):
    global adj

    if node1 not in adj.keys():
        adj[node1] = []

    adj[node1].append(node2)


def bfs(num):
    global adj, q, ans, visited

    q.append(num)

    while len(q) > 0:
        cur = q.popleft()
        
        if not visited[cur]:
            ans.append(cur)
        
        visited[cur] = True

        if cur not in adj.keys():
            continue

        for elem in adj[cur]:
            if not visited[elem]:
                q.append(elem)


def ans_print():
    global ans
    print("bfs search order")

    while len(ans) > 0:
        print("->{}".format(ans.popleft()), end="")


if __name__ == '__main__':
    visited = [False for _ in range(15)]
    adj = {}
    q = deque()
    ans = deque()

    # 1: [2,6,7,9]
    adj_check(1, 2)
    adj_check(1, 6)
    adj_check(1, 7)
    adj_check(1, 9)

    # 2: [3, 4]
    adj_check(2, 3)
    adj_check(2, 4)

    # 4: [5]
    adj_check(4, 5)

    # 6: [4]
    adj_check(6, 4)

    # 7:[8]
    adj_check(7, 8)

    bfs(1)
    ans_print()
