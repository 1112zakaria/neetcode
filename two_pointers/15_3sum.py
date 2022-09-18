class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        """
        Approach:
            - this can be reformatted as a "pick a number i, then 2Sum where sum
            is the negative of i"
            - sort the list of nums
            - iterate for each num i:
                - check if num i is in visited set, continue if True
                - set two pointers, left & right, on the remaining array to the right
                of num i
                - increment the two pointers depending on sum of the pointers need
                to increase or decrease
                    - if num[i] + num[left] + num[right] == 0, add to output list
                - add num i to visited set
            - return output list
        """
        nums.sort()
        #visited = set()
        added = set()
        output = []
        
        for i in range(len(nums)):
            num = nums[i]
            target_sum = -1 * num
            left_ptr = i
            right_ptr = len(nums) - (i+1)
            
            #if num in visited: continue
            #visited.add(num)
            
            while left_ptr < right_ptr:
                left = nums[left_ptr]
                right = nums[right_ptr]
                local_sum = num + left + right
                if local_sum == 0:
                    if (num, left, right) not in added:
                        output += [[num, left, right]]
                        added.add((num, left, right))
                    left_ptr += 1
                elif local_sum > 0:
                    right_ptr -= 1
                else:
                    left_ptr += 1
        return output
            
        