from collections import deque


# adjacency list
def adj_check(n, m):
    global adj
    if n not in adj.keys():
        adj[n] = []

    adj[n].append(m)


def bfs(num):
    global adj, q, ans

    q.append(num)

    while len(q) > 0:
        cur = q.popleft()
        visited[cur] = True
        ans.append(cur)

        if cur not in adj.keys():
            continue

        for elem in adj[cur]:
            if not visited[elem]:
                q.append(elem)


def ans_print():
    global ans
    print("bfs search order")
    temp = ans.popleft()
    print(temp, end="")

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

    # 2: [3,4]
    adj_check(2, 3)
    adj_check(2, 4)

    # 4: [5]
    adj_check(4, 5)

    # 7: [8]
    adj_check(7, 8)

    bfs(1)
    ans_print()
