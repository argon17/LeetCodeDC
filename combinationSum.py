class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        ans= []
        def helper(ind, cur, target):
            if target <= 0:
                if target == 0:
                    ans.append(cur)
                return
            for i, val in enumerate(candidates[ind:], ind):
                helper(i, cur + [val], target - val)
            
        helper(0, [], target)
        return ans