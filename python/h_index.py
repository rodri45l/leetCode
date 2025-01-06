# https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # sort citations from min to max
        citations.sort()
        max_num = len(citations)
        max_h = 0
        for i in range(len(citations)):
            if citations[i] <= (max_num - i) and citations[i] > max_h:
                max_h = citations[i]
            elif (max_num - i) > max_h:
                max_h = min(max_num - i, citations[i])
        return max_h


if __name__ == "__main__":
    solution = Solution()
    test_cases = [
        ([3, 0, 6, 1, 5], 3),
        ([1, 3, 1], 1),
        ([0, 1, 3, 5, 6], 3),
        ([10, 8, 5, 4, 3], 4),
        ([100], 1),
    ]

    for citations, expected in test_cases:
        result = solution.hIndex(citations)
        print(f"hIndex({citations}) = {result}, expected = {expected}")
