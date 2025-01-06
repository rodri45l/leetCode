# Remove Duplicates from Sorted Array
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        next_position = 0
        for i in range(len(nums)):
            if nums[i] != nums[next_position]:
                next_position += 1
                nums[next_position] = nums[i]
        return next_position + 1


if __name__ == "__main__":
    solution = Solution()
    nums = [1, 1, 2]
    length = solution.removeDuplicates(nums)
    print(f"Length of array after removing duplicates: {length}")
    print(f"Array after removing duplicates: {nums[:length]}")
