s = []
stack = []


for sentence in s:
    flag = False
    for elem in sentence:
        if elem == '(':
            stack.append(elem)

        elif elem == ')':
            if not stack:
                flag = True
                print("error")
                exit(0)

            else:
                stack.pop()

if stack or not flag:
    print("error")
else:
    print("good")
