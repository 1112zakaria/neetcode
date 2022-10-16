class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        Seems similar to container most water problem...

        Approach:
            - set left and right ptr on left two values
            - calculate profit and compare with max profit (set default to 0)
            - if profit is negative, shift pointers to next value
            - set right ptr + 1
            - repeat until array is traversed
            - return max value
        """
        if len(prices) == 0: return 0

        left_ptr, right_ptr = 0, 1
        max_profit = 0
        
        while right_ptr < len(prices):
            start, close = prices[left_ptr], prices[right_ptr]
            if start < close:
                profit = close - start
                max_profit = max(max_profit, profit)
            else:
                left_ptr = right_ptr
            right_ptr += 1
        return max_profit
            