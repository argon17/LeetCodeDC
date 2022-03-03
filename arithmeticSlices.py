class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans = 0
        cur = 0
        for ind in range(2, len(nums)):
            if nums[ind] + nums[ind - 2] == 2 * nums[ind - 1]:
                cur += 1
                ans += cur
            else:
                cur = 0
        return ans