class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        count = Counter(nums)
        return sum(k == 0 and count[num] >= 2 or k > 0 and num + k in count for num in count)