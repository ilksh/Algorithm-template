import numpy as np
from game import TicTacToe

INF = 0x3f3f


def array_to_tuple(arr):
    return tuple(x for x in arr)


# return coordinate which is empty
def possible_moves(board):
    return [(r, c) for r in range(3) for c in range(3) if board[r][c] == TicTacToe.EMPTY]


# randomly deploy stone
def random_move(board):
    while True:
        position = array_to_tuple(np.random.randint(0, 3, (2,)))
        if board[position] == TicTacToe.EMPTY:
            return position


# maually deploy stone
def manual(board):
    valid = False
    while not valid:
        try:
            x = int(input("row[0,2]:"))
            y = int(input("col[0,2]:"))

            if all(0 <= i <= 2 for i in [x, y]):
                valid = True
            else:
                print("out of boundary")

        except ValueError:
            print("wrong data was given")

    return (x, y)


# evaluate whether game is over
def evaluate(board):
    # player = current player
    for player in [TicTacToe.PLAYER, TicTacToe.OPPONENT]:
        for indexes in TicTacToe.win_indexes(3):
            if all(board[r][c] == player for r, c in indexes):
                return player

    # check for draw state
    # board != TicTacToe.board
    # board = current board
    if all(x != TicTacToe.EMPTY for x in np.nditer(board)):
        return TicTacToe.DRAW

    return None


# aspect interpretation
def evaluation(board):
    # number of cases that can win
    player_cnt = 0
    opponent_cnt = 0

    for indexes in TicTacToe.win_indexes(3):
        # check for all cases
        if all((board[r][c] == TicTacToe.PLAYER or board[r][c] == TicTacToe.EMPTY) for r, c in indexes):
            player_cnt += 1
        if all((board[r][c] == TicTacToe.OPPONENT or board[r][c] == TicTacToe.EMPTY) for r, c in indexes):
            opponent_cnt += 1

    return player_cnt - opponent_cnt


# depth needs to be made to judge the situation,
# is_max_step discloses who the turn is now (True = my turn)
def minmax(depth, is_max_step, board):
    winner = evaluate(board)  # 4 cases: player, opponent, draw, none

    if winner == TicTacToe.PLAYER:
        return 10

    elif winner == TicTacToe.OPPONENT:
        return -10

    elif winner == TicTacToe.DRAW:
        return 0

    if depth == 2:
        return evaluation(board)

    # search code: need to check whether the current turn is min or max phase
    # my turn = max phase
    if is_max_step:
        best_score = -INF
        for (r, c) in possible_moves(board):
            board[r][c] = TicTacToe.PLAYER  # deploy player
            score = minmax(depth+1, False, board)
            board[r][c] = TicTacToe.EMPTY

            best_score = max(best_score, score)

    # opponent: min phase
    else:
        best_score = INF
        for (r, c) in possible_moves(board):
            board[r][c] = TicTacToe.OPPONENT  # deploy opponent
            score = minmax(depth + 1, True, board)
            board[r][c] = TicTacToe.EMPTY

            best_score = min(best_score, score)

    return best_score


# heuristic algorithm
def ai(board):
    best_score = -INF
    move = (-1, -1)

    for(r, c) in possible_moves(board):
        board[r][c] = TicTacToe.PLAYER
        score = minmax(1, False, board)
        board[r][c] = TicTacToe.EMPTY

        if score > best_score:
            best_score = score
            move = (r, c)

    # ai function has to return the best coordinate
    return move


if __name__ == "__main__":
    from game import TicTacToe

    p = TicTacToe.PLAYER
    o = TicTacToe.OPPONENT
    e = TicTacToe.EMPTY

    initial_board = np.array([[e, e, e],
                              [e, e, e],
                              [e, e, e]])

    game = TicTacToe(draw_board=True, board=initial_board)
    winner, history = game.run(ai, ai)

    if winner == TicTacToe.DRAW:
        print("draw")
    else:
        print(f"winner: {winner}")
