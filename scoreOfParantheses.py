class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        score, depth = 0, 0
        for i, c in enumerate(s):
            if c == '(':
                depth += 1
            else:
                depth -= 1
            if s[i] == ')' and s[i-1] == '(':
                score += 2 ** depth
        return score