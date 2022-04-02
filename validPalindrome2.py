class Solution:
    def validPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        def isValidPal(l, r, allowed):
            while l < r:
                if s[l] != s[r]:
                    if not allowed:
                        return 0
                    allowed -= 1
                    return isValidPal(l, r-1, allowed) or isValidPal(l+1, r, allowed)
                l += 1
                r -= 1
            return 1
        return isValidPal(0, len(s) - 1, 1)
