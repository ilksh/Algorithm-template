class Stack:
    def __init__(self):
        self.stack = []

    def empty(self):
        # Stack is empty
        if len(self.stack) == 0:
            return True

        else: return False

    def size(self): return len(self.stack)
    def clear(self): self.stack = []

    def push(self, data):
        self.stack.append(data)

    def pop(self):
        if self.empty():
            print("unable to pop from empty stack")
            return
        else:
            result = self.stack.pop()
            print("{} was removed from the stack".format(result))

    def print(self):
        print(self.stack)

    def peek(self):
        if self.empty():
            print("stack is empty. unable to perform the operation")
            return

        else:
            print(self.stack[-1])


if __name__ == '__main__':
    s = Stack()
    s.push(1)
    s.push(2)
    s.push(5)
    s.print()   # s = [1,2,5]
    s.pop()     # 5
    s.print()   # s = [1, 2]

    print("size: ", s.size())             # 2
    print("Is stack empty? ", s.empty())  # False
    