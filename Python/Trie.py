class Trie:
    def __init__(self):
        self.child = {}  # Key: number, Value: Trie
        self.finished = False

    def insert(self, phone):
        node = self
        for digit in phone:
            if digit not in node.child:         # operate when there's no targeted number
                node.child[digit] = Trie()      # language C need dynamic allocation

            node = node.child[digit]            # move to next dictionary (Trie)

        node.finished = True                    # inform the end of trie

    def search(self):
        rst = True
        for cur_node in self.child.values():
            if cur_node.finished:
                if len(cur_node.child):
                    return False
                else:
                    return True

            # if anyone is false, the result is false
            temp = cur_node.search()
            if temp is False:
                rst = False

        # check for all case
        # prevent one trie from subsets of other trie
        # Trie 1) 1-2-3-4: 4(end)
        # Trie 2) 1-2-3-4-5-6-7: 7(end)
        # Trie 2 passes Trie 1's end
        return rst


tc = int(input())

for _ in range(tc):
    trie = Trie()

    n = int(input())

    for _ in range(n):
        phone_number = input()
        trie.insert(phone_number)

    if trie.search():
        print("YES")
    else:
        print("NO")
"""
113
12340
123440
12345
98346

1 - 1 - 3
"""