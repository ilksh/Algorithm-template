lyrics = ["Il ((libro dell'amor) mi annoia), (E pesa come l'anima)",
          "(È pieno (di carezze) al) (cuore), E modi (per) (danzare",
          "(Ma, Mi piace quando (lo leggi) tu)",
          "(((E tu di più), (Tu puoi leggermi) il (cielo) (al blu)",
          ")Il libro dell'amore (suona))"]

for sentence in lyrics:
    stack = []

    flag = False

    for elem in sentence:
        if elem == '(':
            stack.append(elem)

        elif elem == ')':
            if len(stack) == 0:
                flag = True
            else:
                stack.pop()

    if not flag and not stack:
        print("success")
    else:
        print("error")
