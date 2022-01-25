class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        l, r = 0, n - 1
        while l + 1 < n and arr[l] < arr[l + 1]:
            l += 1
        while r - 1 >= 0 and arr[r - 1] > arr[r]:
            r -= 1
        return l > 0 and r < n - 1 and l == r
