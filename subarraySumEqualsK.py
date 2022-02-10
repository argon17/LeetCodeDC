class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        store = Counter({0:1})
        ans = 0
        for cur in accumulate(nums):
            ans += store[cur - k]
            store[cur] += 1
        return ans