from collections import deque


# adjacency matrix
def adj_check(n, m):
    # node n and m are connected
    adj[n][m] = True
    adj[m][n] = True


def bfs(num):
    global adj, q, ans

    q.append(num)

    while len(q) > 0:
        cur = q.popleft()
        visited[cur] = True
        ans.append(cur)

        for i in range(1, 10):
            if adj[cur][i] is True and not visited[i]:
                q.append(i)


def ans_print():
    global ans
    print("bfs search order")
    temp = ans.popleft()
    print(temp, end="")

    while len(ans) > 0:
        print("->{}".format(ans.popleft()), end="")


if __name__ == '__main__':
    visited = [False for _ in range(15)]
    adj = [([False] * 10) for _ in range(10)]
    q = deque()
    ans = deque()

    adj_check(1, 2)
    adj_check(1, 6)
    adj_check(1, 7)
    adj_check(1, 9)

    adj_check(2, 3)
    adj_check(2, 4)

    adj_check(4, 5)

    adj_check(7, 8)

    bfs(1)
    ans_print()
