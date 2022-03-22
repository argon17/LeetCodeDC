class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = ['a'] * n
        k -= 1 * n
        for i in range(n):
            if k:
                ans[i] = chr(97 + min(k, 25))
                k -= min(k, 25)
            else:
                break
        return ''.join(reversed(ans))
