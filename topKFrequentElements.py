class Solution:
    def topKFrequent(self, nums, k):
        count = Counter(nums)
        bucket = [[] for _ in range(len(nums) + 1)]
        for num, freq in count.items(): 
            bucket[freq].append(num)
        flat_list = list(chain(*bucket))
        return flat_list[::-1][:k]
