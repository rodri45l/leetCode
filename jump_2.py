from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        current_p = 0
        max_len = len(nums) - 1
        total_steps = 0

        if len(nums) <= 1:  # Handle edge cases
            return 0

        while True:
            total_steps += 1
            gas = nums[current_p]
            next_position = current_p
            max_gas = 0

            # Find the best position to jump to
            for i in range(current_p + 1, min(current_p + gas + 1, len(nums))):
                if i >= max_len:  # Check if we can reach the end
                    return total_steps
                if nums[i] + i > max_gas:
                    next_position = i
                    max_gas = nums[i] + i

            if (
                next_position == current_p
            ):  # Check for stuck condition (shouldn't happen in valid inputs)
                break

            current_p = next_position

        return total_steps


if __name__ == "__main__":
    sol = Solution()
    print(sol.jump([4, 1, 1, 3, 1, 1, 1]))  # Expected output: 2
