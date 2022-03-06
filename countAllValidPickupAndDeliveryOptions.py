class Solution:
    def countOrders(self, n: int) -> int:
        if n == 1:
            return 1
        ans = self.countOrders(n - 1) * (2 * n - 1) * n
        return ans % (10 ** 9 + 7)