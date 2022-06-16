class MakeNode:
    def __init__(self, item, left=None, right=None):
        self.data = item
        self.left = left
        self.right = right


class Node:
    def __init__(self, item):
        self.root = MakeNode(item)

    def insert_left(self, node):
        self.root.left = node

    def insert_right(self, node):
        self.root.right = node


def preorder(node):
    if node is not None:
        print("({})". format(node.root.data), end=" ")
        preorder(node.root.left)
        preorder(node.root.right)


def inorder(node):
    if node is not None:
        inorder(node.root.left)
        print("({})".format(node.root.data), end=" ")
        inorder(node.root.right)


def postorder(node):
    if node is not None:
        postorder(node.root.left)
        postorder(node.root.right)
        print("({})".format(node.root.data), end=" ")


if __name__ == '__main__':

    node = [None for _ in range(7)]

    for idx in range(1, 7):
        node[idx] = Node(idx)

    # link two nodes
    node[1].insert_left(node[2])
    node[1].insert_right(node[3])

    node[2].insert_left(node[4])
    node[2].insert_right(node[5])

    node[3].insert_left(node[6])

    print("===preorder===")
    preorder(node[1])
    print("\n")

    print("===inorder===")
    inorder(node[1])
    print("\n")

    print("===postorder")
    postorder(node[1])










