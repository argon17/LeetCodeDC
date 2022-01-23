class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        q = deque(range(1, 10))
        while q:
            cur = q.popleft()
            if low <= cur <= high:
                ans.append(cur)
            if cur % 10 < 9:
                q.append(cur * 10 + cur % 10 + 1)
        return ans


class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        for now in range(1, 10):
            num = now
            for next in range(now + 1, 10):
                num = num * 10 + next
                if low <= num <= high:
                    ans.append(num)
        ans.sort()
        return ans