def print_sudoku():
    print("=========")
    for r in range(9):
        for c in range(9):
            print(sudoku[r][c], end=" ")
        print()


def bt(blank_idx):  # back tracking
    global sudoku, empty_space

    print_sudoku()

    if blank_idx == len(empty_space):
        print("sudoku solved!!")
        print_sudoku()
        exit()

    # {1: True, 2: True ,,,,, 9: True}
    candidate = {}
    for integer in range(1, 10):
        candidate[integer] = True

    cur_row, cur_col = empty_space[blank_idx]

    #  exclude numbers in the same column and row
    for idx in range(9):
        row_check = sudoku[cur_row][idx]
        candidate[row_check] = False

        col_check = sudoku[idx][cur_col]
        candidate[col_check] = False

    # exclude numbers in the same square
    for row in range(3):
        for col in range(3):
            y = (cur_row//3) * 3 + row
            x = (cur_col//3) * 3 + col
            temp = sudoku[y][x]
            candidate[temp] = False

    # insert numbers which was not excluded
    for integer in range(1, 10):
        if candidate[integer] is True:
            sudoku[cur_row][cur_col] = integer
            bt(blank_idx+1)

    # remove option which is not promising by using the backtracking algorithm
    sudoku[cur_row][cur_col] = 0
    print_sudoku()


if __name__ == '__main__':
    sudoku = [ [2, 0, 8, 5, 6, 0, 1, 0, 0],
               [9, 5, 0, 7, 0, 1, 0, 4, 8],
               [0, 7, 3, 4, 0, 2, 9, 0, 6],
               [0, 8, 0, 0, 1, 7, 4, 3, 2],
               [7, 0, 1, 3, 0, 0, 5, 0, 9],
               [4, 0, 2, 0, 9, 5, 7, 6, 0],
               [0, 0, 5, 9, 0, 6, 0, 1, 0],
               [6, 9, 0, 0, 4, 3, 8, 0, 5],
               [0, 1, 0, 2, 0, 8, 6, 0, 7]]

    empty_space = []

    for i in range(9):
        for j in range(9):
            if sudoku[i][j] == 0:
                empty_space.append((i, j))

    bt(0)
