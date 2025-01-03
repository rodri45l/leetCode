# https://leetcode.com/problems/n-queens/
MAX_X = 4
MAX_Y = 4
from typing import List


class Solution:
    def __init__(self):
        self.solutions = []

    def place_queen(self, index):
        row = "...."
        return row[:index] + "Q" + row[index + 1 :]

    def check_sol(self, partial_sol: List[str]):
        # Only check the last row
        y_coordinate = len(partial_sol) - 1
        row_to_check = partial_sol[y_coordinate]
        # Locate queen
        for i in range(4):
            if row_to_check[i] == "Q":
                x_coordinate = i
        # check

    def solve(self, n, partial_solution=None):
        if not partial_solution:
            for i in range(4):
                # place the queen
                index = i  # Replace the character at this index
                partial_sol = self.place_queen(index)
                self.solve(n, partial_sol)
            return
        else:
            queens_placed = len(partial_solution)

        # place the queen on the partial solution
        # check if meets criteria
        # if it does recurse to the next one

    def solveNQueens(self, n: int) -> List[List[str]]:
        self.solve(n)
        return self.solutions


if __name__ == "__main__":
    solution = Solution()
    solution.solveNQueens()
