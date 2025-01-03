# https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150
from typing import List

# Retarded solution
# class Solution:
#     def rotate(self, nums: List[int], k: int) -> None:
#         """
#         Do not return anything, modify nums in-place instead.
#         """

#         while k != 0:
#             nums.insert(0, nums.pop())
#             k -= 1


# Much MUCH MUCH better solution
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n  # Handle cases where k is larger than the size of the list
        nums[:] = nums[-k:] + nums[:-k]


if __name__ == "__main__":
    sol = Solution()
    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3
    sol.rotate(nums, k)
    print(nums)  # Output should be [5, 6, 7, 1, 2, 3, 4]
