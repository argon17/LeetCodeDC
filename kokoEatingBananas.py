class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def possible(mid) -> bool:
            cur = 0
            for pile in piles:
                cur += (pile + mid - 1) // mid
                if cur > h:
                    return 0
            return 1
        lo, hi, ans = 1, 1000000000, 0
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if possible(mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return ans
        