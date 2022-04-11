class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        def reverse(lo, hi):
            while lo < hi:
                i1, j1 = lo // m, lo % m
                i2, j2 = hi // m, hi % m
                grid[i1][j1], grid[i2][j2] = grid[i2][j2], grid[i1][j1]
                lo += 1
                hi -= 1
        k %= n * m
        reverse(0, n * m - 1)
        reverse(0, k - 1)
        reverse(k, n * m - 1)
        return grid
