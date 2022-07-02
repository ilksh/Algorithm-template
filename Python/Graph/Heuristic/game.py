from typing import ValuesView
import numpy as np
import os


class TicTacToe:

    BOARD_SHAPE = (3, 3)  # Size of board 3 x3

    EMPTY = " "
    PLAYER = "X"
    OPPONENT = "O"

    DRAW = "DRAW"

    def __init__(self, board=None, draw_board=True):

        self.board = None
        self.current_player = None
        self.draw_board = draw_board

        if board is not None:
            players = 0
            opponents = 0

            for i in np.nditer(board):
                if i == TicTacToe.PLAYER:
                    players += 1
                elif i == TicTacToe.OPPONENT:
                    opponents += 1

            if abs(players - opponents) >= 2:
                raise ValueError("Given initial board condition is not possible")

            self.initial_board = board

        else:
            self.initial_board = np.full(self.BOARD_SHAPE, self.EMPTY)

    def reset(self):
        # initialize game status
        self.board = self.initial_board.copy()
        self.current_player = TicTacToe.next_player(self.board)

    def evaluate(self):
        # after confirming the results of the game, return the winner
        for player in [self.PLAYER, self.OPPONENT]:
            for indexes in self.win_indexes(self.BOARD_SHAPE[0]):
                if all(self.board[r][c] == player for r, c in indexes):
                    return player

        # draw
        if all(x != TicTacToe.EMPTY for x in np.nditer(self.board)):
            return TicTacToe.DRAW

        return None

    def draw(self):
        if self.draw_board:
            print(TicTacToe.format_board(self.board), end="\n\n")

    # TicTacToe is turn-based game
    def switch_turn(self):
        if self.current_player == TicTacToe.OPPONENT:
            self.current_player = TicTacToe.PLAYER
        else:
            self.current_player = TicTacToe.OPPONENT

    def action(self, player, position):
        if type(position) is not tuple:
            raise TypeError("position should be tuple")
        if len(position) > 2:
            raise ValueError("position should have only two values")

        if self.board[position] not in [TicTacToe.PLAYER, TicTacToe.OPPONENT]:
            self.board[position] = player

        else:
            raise ValueError("position {} already has {}".format(position, self.board[position]))

    def run(self, player_method, opponent_method):
        self.reset()
        winner = None
        history = []

        # until the winner is calculated
        while not winner:
            self.draw()
            if self.current_player == TicTacToe.PLAYER:
                position = player_method(self.board)
            else:
                position = opponent_method(self.board)
            self.action(self.current_player, position)

            self.switch_turn()
            history.append((self.current_player, position))
            winner = self.evaluate()

        self.draw()

        return winner, history

    @staticmethod
    def win_indexes(n):
        # yield = # of all cases that win
        for r in range(n):
            yield [(r, c) for c in range(n)]

        for c in range(n):
            yield [(r, c) for r in range(n)]

        yield [(i, i) for i in range(n)]

        yield [(i, n - 1 - i) for i in range(n)]

    @staticmethod
    def format_row(row):
        return '|' + '|'.join('{0:^3s}'.format(x) for x in row) + '|'

    @staticmethod
    def format_board(board):
        return '\n'.join(TicTacToe.format_row(row) for row in board)

    @staticmethod
    def clear_console():
        os.system('cls' if os.name == 'nt' else 'clear')

    @staticmethod
    def next_player(board):
        # if all boards are empty, randomly select player to start
        # if all boards are not empty, switch the turn
        opponents = 0
        players = 0

        for x in np.nditer(board):
            if x == TicTacToe.PLAYER:
                players += 1
            elif x == TicTacToe.OPPONENT:
                opponents += 1

        if opponents == players:
            if np.random.uniform() < 0.5:
                return TicTacToe.PLAYER
            else:
                return TicTacToe.OPPONENT

        return TicTacToe.PLAYER if opponents > players else TicTacToe.OPPONENT
