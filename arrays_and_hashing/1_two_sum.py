class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Approach 1 (cache):
            - iterate over all of the nums
            - for each num, 
                - map the index of num at key num (list of indices)
                - check that there exist indices mapped at diff_key = target - key
                    - if true and !( diff_key == key && len(cache[diff_key]) < 2 ),
                        - return pair [ curr_index, cache[diff_key][0] ]
        """
        cache = {}
        for curr_index in range(len(nums)):
            num = nums[curr_index]
            if num not in cache:
                cache[num] = []
            cache[num] += [curr_index]
            
            diff = target - num
            if diff in cache and not (diff == num and len(cache[diff]) < 2):
                return [curr_index, cache[diff][0]]
        return None
                
        