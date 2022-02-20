class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x : (x[0], -x[1]))
        ans = covered = 0
        for start, end in intervals:
            ans += covered < end
            covered = max(covered, end)
        return ans
                