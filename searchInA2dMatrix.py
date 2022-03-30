class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n, m = len(matrix), len(matrix[0])
        lo, hi = 0, n*m - 1
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            here = matrix[mid // m][mid % m]
            if here == target:
                return True
            elif here < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return False
