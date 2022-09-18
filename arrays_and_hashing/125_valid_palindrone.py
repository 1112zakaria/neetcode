class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        
        if s == "": return True
        print(s)
        left_ptr = 0
        right_ptr = len(s) - 1
        if s[left_ptr] != s[right_ptr]: return False
        while left_ptr < right_ptr:
            left_ptr += 1
            right_ptr -= 1
            if s[left_ptr] != s[right_ptr]: return False
        return True
        
            