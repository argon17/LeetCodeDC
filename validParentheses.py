class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {')':'(', '}':'{', ']':'['}
        for c in s:
            if c in mapping:
                if stack and stack[-1] == mapping[c]:
                    stack.pop()
                else:
                    return 0
            else:
                stack.append(c)
        return not stack