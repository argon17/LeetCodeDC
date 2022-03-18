class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        last = {c : i for i, c in enumerate(s)}
        stack = []
        done = set()
        for i, c in enumerate(s):
            if c in done:
                continue
            while stack and stack[-1] > c and last[stack[-1]] > i:
                done.remove(stack.pop())
            stack.append(c)
            done.add(c)
        return ''.join(stack)
