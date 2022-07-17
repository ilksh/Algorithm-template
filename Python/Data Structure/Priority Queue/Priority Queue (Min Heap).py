class Priority_Queue:
    def __init__(self):
        self.cnt = 0
        self.heap = [int(1e9) for _ in range(100)]

    def size(self):
          return self.cnt

    def swap(self, a_idx, b_idx):
        temp = self.heap[a_idx]
        self.heap[a_idx] = self.heap[b_idx]
        self.heap[b_idx] = temp

    def push(self, item):
        self.cnt += 1
        self.heap[self.cnt] = item

        cur = self.cnt

        while cur > 1:
            par = cur >> 1

            if self.heap[cur] > self.heap[par]: break

            self.swap(cur, par)
            cur = par

    def pop(self):
        self.heap[1] = self.heap[self.cnt]
        self.cnt -= 1

        cur = 1

        while cur <= self.cnt:
            left = cur << 1 if ((cur << 1) <= self.cnt) else -1
            right = (cur << 1 | 1) if ((cur << 1 | 1) <= self.cnt) else -1
            child = cur

            if left == -1:
                break

            if self.heap[cur] > self.heap[left]:
                child = left

            if right != -1 and self.heap[child] > self.heap[right]:
                child = right

            if child == left:
                self.swap(cur, left)
                cur = left

            elif child == right:
                self.swap(cur, right)
                cur = right

            else:
                break

    def top(self):
        return self.heap[1]

    def empty(self):
        if self.cnt == 0:
            return True

        return False


if __name__ == '__main__':
    pq = Priority_Queue()

    pq.push(17)
    pq.push(5)
    pq.push(10)
    pq.push(19)
    pq.push(21)
    pq.push(8)

    while not pq.empty():
        print(pq.top(), end=" ")
        pq.pop()


