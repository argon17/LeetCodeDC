class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        start, end = 0, -1
        last = {}
        for ind, char in enumerate(s):
            last[char] = ind
        ans = []
        for ind, char in enumerate(s):
            end = max(end, last[char])
            if ind == end:
                ans.append(end - start + 1)
                start = end + 1
        return ans
