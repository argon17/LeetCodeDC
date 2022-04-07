class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = [-stone for stone in stones]
        heapq.heapify(pq)
        while len(pq) > 1:
            a, b = heapq.heappop(pq), heapq.heappop(pq)
            d = abs(a - b)
            heapq.heappush(pq, -d)
        return -pq[0]
