class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.pq = []
        self.k = k
        pq = self.pq
        for num in nums:
            heapq.heappush(pq, num)
            if len(pq) > k:
                heapq.heappop(pq)

    def add(self, val: int) -> int:
        k, pq = self.k, self.pq
        heapq.heappush(pq, val)
        if len(pq) > k:
            heapq.heappop(pq)
        return pq[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
