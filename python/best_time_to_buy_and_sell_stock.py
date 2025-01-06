# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        min_price = float("inf")
        max_profit = 0
        for price in prices:
            if price < min_price:
                min_price = price
                continue
            profit = price - min_price
            if profit > max_profit:
                max_profit = profit
        return max_profit


if __name__ == "__main__":
    solution = Solution()
    test_prices = [1, 2]
    print(f"Max profit for {test_prices} is {solution.maxProfit(test_prices)}")
