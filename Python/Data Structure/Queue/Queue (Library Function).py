from collections import deque


class Queue:
    def __init__(self):
        self.queue = deque()

    def empty(self):
        if len(self.queue) == 0:
            return True
        else:
            return False

    def size(self): return len(self.queue)
    def clear(self): self.queue = deque()

    def enqueue(self, data):
        self.queue.append(data)

    def dequeue(self):
        if self.empty():
            print("unable to dequeue from empty queue")
            return
        else:
            result = self.queue.popleft()
            print("{} was removed from the queue".format(result))

    def print_queue(self):
        print(self.queue)


if __name__ == '__main__':
    q = Queue()
    q.dequeue()  # Error message

    # deque([10, 30, 50, 70, 90])
    for num in range(10, 100, 20):
        q.enqueue(num)

    q.print_queue()
    q.dequeue()      # deque 10
    q.enqueue(55)
    q.print_queue()  # deque([30, 50, 70, 90, 55])
