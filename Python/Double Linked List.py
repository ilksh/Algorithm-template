class MakeNode:
    def __init__(self, element, prev=None, nxt=None):
        self.element = element
        self.prev = prev
        self.nxt = nxt


class DoubleLinkedList:
    def __init__(self, item):
        self.head = MakeNode(item)

    def empty(self):
        if self.head is None:
            return True
        return False

    def insert_left(self, item):
        p = MakeNode(item)
        p.nxt = self.head.nxt
        self.head.nxt = p
        p.prev = self.head

    def insert_right(self, item):
        if self.empty():
            self.head = MakeNode(item)

        else:
            cur = self.head
            while cur.nxt:
                cur = cur.nxt

            new_node = MakeNode(item)
            cur.nxt = new_node
            new_node.prev = cur

    def pop_left(self):
        top = self.head
        cur = top.nxt
        top.nxt = cur.nxt
        if cur.nxt:
            cur.nxt.prev = cur.prev

    def print_list(self):
        if self.empty():
            print("None")
            return

        cur = self.head
        while cur.nxt:
            cur = cur.nxt
            print(cur.element, "-> ", end="")

        print("None")


if __name__ == '__main__':
    lst = DoubleLinkedList(-1)

    for i in range(3):
        lst.insert_left(i+1)
        lst.print_list()

    for _ in range(3):
        lst.pop_left()
        lst.print_list()

    for i in range(3):
        lst.insert_right(i+1)
        lst.print_list()

    for _ in range(3):
        lst.pop_left()
        lst.print_list()

"""
===insert left===
1 -> None
2 -> 1 -> None
3 -> 2 -> 1 -> None
===pop===
2 -> 1 -> None
1 -> None
None

===insert right===
1 -> None
1 -> 2 -> None
1 -> 2 -> 3 -> None
===pop===
2 -> 3 -> None
3 -> None
None
"""








