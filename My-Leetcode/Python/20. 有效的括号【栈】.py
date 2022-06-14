class Solution:
    def isValid(self, s: str) -> bool:
        self.bracket = {
            "(": ")",
            "{": "}",
            "[": "]"
        }
        stack = []
        for c in s:
            if self.bracket.get(c, False):
                stack.append(c)
            else:
                if len(stack) > 0 and self.bracket[stack[-1]] == c:
                    stack = stack[:-1]
                else:
                    return False
        if len(stack) > 0:
            return False
        return True