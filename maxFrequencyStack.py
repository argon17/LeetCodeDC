class FreqStack:

    def __init__(self):
        self.count = collections.Counter()
        self.elementsWithCount = collections.defaultdict(list)
        self.maxOccurence = 0

    def push(self, val: int) -> None:
        self.count[val] += 1
        self.elementsWithCount[self.count[val]].append(val)
        self.maxOccurence = max(self.maxOccurence, self.count[val])

    def pop(self) -> int:
        ans = self.elementsWithCount[self.maxOccurence].pop()
        if not self.elementsWithCount[self.maxOccurence]:
            self.maxOccurence -= 1
        self.count[ans] -= 1
        return ans


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()