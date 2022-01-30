class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverseRange(l, r):
            while l < r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        k, n = k % len(nums), len(nums)
        reverseRange(0, n - 1)
        reverseRange(0, k - 1)
        reverseRange(k, n - 1)
        
