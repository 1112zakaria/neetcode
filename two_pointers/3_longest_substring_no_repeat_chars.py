class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        Approach:
            - maintain set of characters in substring, and max len of substr
            - shift right ptr to the right every iteration
            - if right char exists in substr, remove left char and shift until
            right char is not in substr
            - compare len of substr to max len, get max len substr
            - iterate until right ptr is not < len(s)
        """
        if len(s) < 2: return len(s)

        left_ptr = 0
        substr_chars = set()
        substr_chars.add(s[left_ptr])
        longest_substr_len = 1

        for right_ptr in range(1, len(s)):
            # get local longest substr
            left_char = s[left_ptr]
            right_char = s[right_ptr]
            while right_char in substr_chars:
                # remove duplicates
                substr_chars.remove(left_char)
                left_ptr += 1
                left_char = s[left_ptr]
                #substr_chars.add(left_char)
            substr_chars.add(right_char)
            longest_substr_len = max(longest_substr_len, len(substr_chars))
        return longest_substr_len