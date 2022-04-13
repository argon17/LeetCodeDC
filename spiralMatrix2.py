class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        def inside(i, j):
            return 0 <= i < n and 0 <= j < n
        ans = [[-1] * n for _ in range(n)]
        i, j = 0, -1
        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        val = 1
        while val <= n * n:
            for r, c in dirs:
                while inside(i + r, j + c) and ans[i + r][j + c] == -1:
                    i += r
                    j += c
                    ans[i][j] = val
                    val += 1
        return ans
