class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """
        Approach:
            - store nums in set to allow for O(1) lookup
            - for each element num:
                - if there exists an element num-1, continue. num is not
                the first element in the sequence
                - set num as the start of a sequence, while next does not
                exist, continue adding to the sequence (Q, optimization: do we need to store
                the values? we just need length)
                - record length of sequence
           - return longest length     
        """
        num_set = set(nums)
        len_lcs = 0
        for num in num_set:
            if num - 1 not in num_set:
                # is start val of sequence
                local_len_cs = 1
                curr_num = num + 1
                while curr_num in num_set:
                    local_len_cs += 1
                    curr_num += 1
                len_lcs = local_len_cs if local_len_cs > len_lcs else len_lcs
        return len_lcs
        