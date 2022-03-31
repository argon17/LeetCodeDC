class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        lo, hi = max(nums), sum(nums)
        def cantAccomodateInM(ans):
            cur, cnt = 0, 1
            for num in nums:
                cur += num
                if cur > ans:
                    cur = num
                    cnt += 1
                    if cnt > m:
                        return True
            return False
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if cantAccomodateInM(mid):
                lo = mid + 1
            else:
                hi = mid
        return lo
