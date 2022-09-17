class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        Approach:
            - calculate the product of all numbers to the left of and including element
                i (prefix)
            - calcualate the product for all numbers to the right of and including element
                i (postfix)
            - for each num, multiply prefix[i-1] and postfix[i+1]
            - return output array
        
        """
        prefix = [1 for i in range(len(nums))]
        postfix = [1 for i in range(len(nums))]
        output = [0 for i in range(len(nums))]
        
        for i in range(len(nums)):
            left_ptr = i
            right_ptr = len(nums) - (i+1)
            prefix[left_ptr] = nums[left_ptr]
            postfix[right_ptr] = nums[right_ptr]
            if left_ptr > 0:
                prefix[left_ptr] *= prefix[left_ptr-1]
            if right_ptr < len(nums) - 1:
                postfix[right_ptr] *= postfix[right_ptr+1]
        
        for i in range(len(nums)):
            prefix_val = 1 if i-1 < 0 else prefix[i-1]
            postfix_val = 1 if i+1 >= len(nums) else postfix[i+1]
            output[i] = prefix_val * postfix_val
        return output
        