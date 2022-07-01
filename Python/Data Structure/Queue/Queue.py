class Queue:
    def __init__(self):
        self.front = -1
        self.rear = -1
        self.queue = [None for _ in range(1000)]

    def empty(self):
        if self.front == self.rear:
            return True
        return False

    def print_queue(self):
        if self.empty():
            print("Queue is empty")
            return
        print("Queue = [",end=" ")
        for i in range(self.front + 1, self.rear+1):
            print(self.queue[i], end=" ")
        print("]")

    def enqueue(self, data):
        self.rear += 1
        self.queue[self.rear] = data

    def dequeue(self):
        self.front += 1


if __name__ == '__main__':
    q = Queue()
    q.enqueue(1)
    q.enqueue(3)
    q.enqueue(5)
    q.enqueue(7)
    q.enqueue(9)    # Queue = [ 1 3 5 7 9 ]
    q.print_queue()
    q.dequeue()     # Queue = [ 3 5 7 9 ]
    q.print_queue()