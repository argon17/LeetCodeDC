class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        indexPop = 0
        stack = []
        for ele in pushed:
            stack.append(ele)
            while stack and popped[indexPop] == stack[-1]:
                stack.pop()
                indexPop += 1
        return len(stack) == 0