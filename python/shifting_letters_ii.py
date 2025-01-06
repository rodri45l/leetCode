# https://leetcode.com/problems/shifting-letters-ii/submissions/1498578553/?envType=daily-question&envId=2025-01-05
class Solution:
    def shift_letter(self, shift: int, letter: str):
        letter_ascii = ord(letter) - 97
        letter_ascii = (letter_ascii + shift) % 26

        return chr(letter_ascii + 97)

    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        s = list(s)
        n = len(s)
        shifts_diff = [0] * (n + 1)
        for start, end, direction in shifts:
            value = 1 if direction == 1 else -1
            shifts_diff[start] += value
            shifts_diff[end + 1] -= value
        running_sum = 0
        for i in range(n):
            running_sum += shifts_diff[i]
            s[i] = self.shift_letter(running_sum, s[i])

        return "".join(s)
