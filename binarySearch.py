class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l = floor(log2(n))
        cur = 0
        while l >= 0:
            if (cur + (1<<l)) < n and nums[cur + (1<<l)] <= target:
                cur += (1<<l)
                l = floor(log2(n-cur))
            l -= 1
        return cur if nums[cur] == target else -1
