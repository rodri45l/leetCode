# https://leetcode.com/problems/remove-element


class Solution:
    def removeElement(self, nums, val):
        # Two pointers: one for the current position, one for the next position to keep
        next_position = 0

        # Iterate through the array
        for current in range(len(nums)):
            # If the current element is not equal to the target value, move it to the next position
            if nums[current] != val:
                nums[next_position] = nums[current]
                next_position += 1

        # Return the length of the modified array
        return next_position


if __name__ == "__main__":
    print(Solution().removeElement([3, 2, 2, 3], 3))
