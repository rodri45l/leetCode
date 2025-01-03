from typing import List
from collections import Counter


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts = Counter(nums)
        return max(counts.keys(), key=counts.get)


if __name__ == "__main__":
    sol = Solution()
    test_cases = [
        ([3, 2, 3], 3),
        ([2, 2, 1, 1, 1, 2, 2], 2),
        ([1], 1),
        ([1, 1, 2, 2, 2], 2),
    ]

    for nums, expected in test_cases:
        result = sol.majorityElement(nums)
        assert (
            result == expected
        ), f"Test failed for input {nums}. Expected {expected}, got {result}"
    print("All tests passed.")
