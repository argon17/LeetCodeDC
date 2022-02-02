class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n, k = len(s), len(p)
        goal = Counter(p)
        cur = Counter()
        ans = []
        for i in range(n):
            cur[s[i]] += 1
            if i >= k:
                cur[s[i - k]] -= 1
            if cur == goal:
                ans.append(i - k + 1)
        return ans
