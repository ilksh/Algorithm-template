def find(x):  # return the root of x
    global par

    if par[x] == -1:
        return x

    par[x] = find(par[x])

    return par[x]


def union(a, b):
    # minimizing the number of 'find' function calls
    a = find(a)
    b = find(b)

    if a == b:
        return

    par[a] = b


if __name__ == '__main__':
    n = 5   # number of node
    m = 7   # number of edge

    # initialize: assume that there is no parent
    par = [-1 for i in range(n+1)]

    edge_list = []
    mst = 0

    # edge_list.append((w, node1, node2))
    # node1 and node2 are connected with edge whose weight is w
    edge_list.append((10, 1, 2))
    edge_list.append((2, 1, 3))
    edge_list.append((3, 2, 3))
    edge_list.append((7, 2, 5))
    edge_list.append((2, 3, 5))
    edge_list.append((16, 3, 4))
    edge_list.append((8, 4, 5))

    edge_list.sort()

    for w, u, v in edge_list:
        # node u and v are not same component
        if find(u) != find(v):
            print("({})--[{}]--({})".format(u, w, v))
            mst += w
            union(u, v)

    print("minimum: ", mst)