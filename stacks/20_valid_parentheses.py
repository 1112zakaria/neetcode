class Solution:
    def isValid(self, s: str) -> bool:
        """
        Approach:
            - add to stack when open, pop from stack
            when close?
            - if curr is open type, add to stack
            - if curr is close type, check that top of stack contains
            valid open type, if true, pop from stack, else return False
        """
        if len(s) == 1: return False

        open_bracket_map = {
            '}': '{',
            ')': '(',
            ']': '['
        }
        open_brackets = {'(', '{', '['}
        closed_brackets = {')', '}', ']'}
        open_bracket_stack = []

        def pop_open_bracket(close_bracket):
            open_bracket = open_bracket_map[close_bracket]
            if len(open_bracket_stack) == 0:
                return False
            popped_bracket = open_bracket_stack.pop()
            if popped_bracket != open_bracket:
                return False
            return True
        
        for bracket in s:
            if bracket in open_brackets:
                open_bracket_stack.append(bracket)
            else:
                if not pop_open_bracket(bracket): return False

        if len(open_bracket_stack) > 0:
            return False
        return True

