class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        lo, hi = 0, len(nums) - 1
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if nums[mid] == target:
                return True
            if nums[lo] == nums[mid] == nums[hi]:
                lo += 1
                hi -= 1
            elif nums[mid] <= nums[hi]:
                if target < nums[mid] or nums[hi] < target:
                    hi = mid - 1
                else:
                    lo = mid + 1
            else:
                if target < nums[lo] or nums[mid] < target:
                    lo = mid + 1
                else:
                    hi = mid - 1
        return False
