class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        return reduce(lambda x, y : x + y, [(26 ** (len(columnTitle) - pos)) * (ord(ele) - 64) for pos, ele in enumerate(columnTitle, 1)])