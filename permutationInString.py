class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        k, n = len(s1), len(s2)
        goal, cur = [0] * 26, [0] * 26
        for c in s1:
            goal[ord(c) - ord('a')] += 1
        for i in range(n):
            cur[ord(s2[i]) - ord('a')] += 1
            if i >= k:
                cur[ord(s2[i - k]) - ord('a')] -= 1
            if goal == cur:
                return True
        return False