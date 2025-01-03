# Remove Duplicates from Sorted Array
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0

        # Index to place the next valid element
        write_index = 1
        count = 1  # Counter for occurrences of the current number

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                count += 1
            else:
                count = 1

            # Allow the element if count <= 2
            if count <= 2:
                nums[write_index] = nums[i]
                write_index += 1

        return write_index


if __name__ == "__main__":
    solution = Solution()
    nums = [1, 1, 1]
    length = solution.removeDuplicates(nums)
    print(f"Length of array after removing duplicates: {length}")
    print(f"Array after removing duplicates: {nums[:length]}")
