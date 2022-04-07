class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        count = collections.defaultdict(int)
        for ele in arr:
            count[ele] += 1
        elements = list(count.keys())
        mod = 1000000007
        ans = 0
        for a in elements:
            for b in elements:
                c = target - a - b
                if not count[c]:
                    continue
                if a < b and b < c:
                    ans += count[a] * count[b] * count[c]
                elif a < b and b == c:
                    ans += (count[a] * count[b] * (count[b] - 1)) // 2
                elif a == b and b < c:
                    ans += (count[a] * (count[a] - 1) * count[c]) // 2
                elif a == b and b == c:
                    ans += (count[a] * (count[a] - 1) * (count[a] - 2)) // 6
                ans %= mod
        return ans
