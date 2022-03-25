class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda x : x[0]-x[1])
        ans, n = 0, len(costs)
        for ind, cost in enumerate(costs):
            ans += cost[0] if ind < n//2 else cost[1]
        return ans
