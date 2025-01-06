# https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150
from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        gas = 0
        for n in nums:
            if gas < 0:
                return False
            elif n > gas:
                gas = n
            gas -= 1

        return True
