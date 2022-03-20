class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        topCount, bottomCount, sameCount = [0] * 7, [0] * 7, [0] * 7
        n = len(tops)
        for i in range(n):
            topCount[tops[i]] += 1
            bottomCount[bottoms[i]] += 1
            if not tops[i] ^ bottoms[i]:
                sameCount[tops[i]] += 1
        ans = float('inf')
        for num in range(1, 7):
            if topCount[num] + bottomCount[num] - sameCount[num] == n:
                ans = min(ans, n - topCount[num], n - bottomCount[num])
        return ans if ans != float('inf') else -1
