MAX_SIZE = 10

class CircularQueue:
    def __init__(self):
        self.front = 0
        self.rear = 0
        self.array = [None] * MAX_SIZE

    def empty(self):
        if self.front == self.rear:
            return True
        return False

    def full(self):
        if self.front == (self.rear + 1) % MAX_SIZE:
            return True
        return False

    def print(self):
        if self.empty():
            print("Circular Queue is empty")
            return
        print("(front: {} rear: {})".format(self.front, self.rear))
        ans = []
        if self.front < self.rear:
            ans = self.array[self.front+1:self.rear]
        else:
            ans = self.array[self.front+1:MAX_SIZE] + self.array[0:self.rear + 1]
        print("q: ", ans)

    def enqueue(self, item):
        if self.full():
            print("Circular Queue is saturated")
            return
        self.rear = (self.rear + 1) % MAX_SIZE
        self.array[self.rear] = item

    def deque(self):
        if self.empty():
            print("Circular Queue is empty")
            return
        self.front = (self.front + 1) % MAX_SIZE
        result = self.array[self.front]
        print(result, " was removed")


if __name__ == '__main__':
    q = CircularQueue()
    num = 1

    while not q.full():  # (front: 0 rear: 9)
        q.enqueue(num)
        num += 2

    q.print()            # q:  [1, 3, 5, 7, 9, 11, 13, 15]

    for _ in range(3):   # remove 1, 3 ,5 -> (front: 3 rear: 9)
        q.deque()

    q.print()            # q:  [7, 9, 11, 13, 15]
