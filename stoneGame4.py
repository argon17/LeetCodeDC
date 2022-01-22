#  Iterative
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        ans = [0] * (n + 1)
        for stone in range(1, n + 1):
            for i in range(floor(sqrt(stone)), 0, -1):
                if not ans[stone - i * i]:
                    ans[stone] = 1
                    break
        return ans[n]

#  Recursive
class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        @cache
        def isWinning(stone):
            if not stone:   
                return False
            for i in range(floor(sqrt(stone)), 0, -1):
                if not isWinning(stone - i * i): 
                    return True
            return False
        return isWinning(n)