class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit, min_price = 0, 1e5
        for cur_price in prices:
            min_price = min(min_price, cur_price)
            max_profit = max(max_profit, cur_price - min_price)
        return max_profit