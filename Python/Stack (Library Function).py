class Stack:
    def __init__(self):
        self.stack = [None for _ in range(10000)]
        self.top = -1

    def empty(self):
        if self.top == -1:
            return True
        return False

    def push(self, data):
        self.top += 1
        self.stack[self.top] = data

    def pop(self):
        self.top -= 1

    def print_stack(self):
        print("stack = [ ", end="")
        for i in range(self.top+1):
            print(self.stack[i], end=" ")
        print("]")


if __name__ == '__main__':
    s = Stack()

    s.push(1)
    s.push(3)
    s.push(5)
    s.push(7)   # stack = [ 1 3 5 7 ]
    s.print_stack()
    s.pop()     # stack = [ 1 3 5 ]
    s.print_stack()

    print(s.empty())    # False