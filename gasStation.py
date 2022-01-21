class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        totGas = totCost = cur = ans = 0
        for i, (g, c) in enumerate(zip(gas, cost)):
            totGas += g
            totCost += c
            cur += g - c
            if cur < 0:
                ans = i + 1
                cur = 0
        return ans if totGas >= totCost else -1