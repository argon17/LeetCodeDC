class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        index = defaultdict(list)
        for ind, char in enumerate(t):
            index[char].append(ind)
        prev = 0
        for ind, char in enumerate(s):
            cur = bisect_left(index[char], prev)
            if cur == len(index[char]):
                return 0
            prev = index[char][cur] + 1
        return 1