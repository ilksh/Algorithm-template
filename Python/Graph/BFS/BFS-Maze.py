from collections import deque


def out_of_boundary(row, col):
    if row < 0 or row >= 6 or col < 0 or col >= 8:
        return True
    return False


def maze_print():
    print("===step{}====".format(cnt))
    for i in range(6):
        for j in range(8):
            print(maze[i][j], end=" ")
        print("")


def bfs(row, col):
    global maze, visited, cnt

    q = deque()

    maze[row][col] = 'x'
    visited[row][col] = True
    q.append((row, col))

    maze_print()

    while len(q) > 0:
        cur_row, cur_col = q.popleft()

        for dir in range(4):
            new_row = cur_row + dy[dir]
            new_col = cur_col + dx[dir]

            if out_of_boundary(new_row, new_col):
                continue

            if maze[new_row][new_col] == 'e':
                print("Find the exit!")
                print("Search {} times".format(cnt))
                exit(0)

            if not visited[new_row][new_col] and maze[new_row][new_col] == '0':
                cnt += 1
                maze[new_row][new_col] = 'x'
                maze_print()

                q.append((new_row, new_col))


if __name__ == '__main__':
    maze = [['s', '0', '1', '1', '1', '1', '1', '1'],
            ['1', '0', '0', '0', '1', '0', '0', '1'],
            ['1', '1', '0', '1', '0', '0', '1', '1'],
            ['1', '1', '0', '1', '0', '0', '0', '1'],
            ['1', '0', '0', '0', '0', '1', '0', 'e'],
            ['1', '1', '0', '1', '1', '1', '1', '1']]

    visited = [[False for _ in range(8)] for _ in range(7)]

    # delta y, x
    dy = [0, 0, -1, 1]
    dx = [-1, 1, 0, 0]

    cnt = 1

    bfs(0, 0)