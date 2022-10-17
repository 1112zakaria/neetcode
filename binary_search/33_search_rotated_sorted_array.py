class Solution:
    def search(self, nums: List[int], target: int) -> int:
        """
        Approach:
            - start at middle of array, recursively compare start,
            middle, and end of subarray?
            - Cases:
                - 1. start < middle < end: no shift
                - 2. start > middle < end: shift line is below midpoint
                - 3. start < middle > end: shift line is above midpoint
            - search subarray where target is in range, until value is found
        """
        if nums == []: return -1
        return self.searchSubarray(nums, 0, len(nums)-1, target)

    def searchSubarray(self, nums, s, e, target):
        if e-s == 0:
            num = nums[s]
            if num == target:
                return num
            return -1
        
        midpoint = s + (s - e) // 2
        start, middle, end = nums[s], nums[midpoint], nums[e]
        result = None

        if start <= middle <= end:
            # no shift
            if target <= middle:
                result = self.searchSubarray(nums, s, midpoint, target)
            else:
                result = self.searchSubarray(nums, midpoint+1, e, target)
            
        elif start >= middle <= end:
            # shift, but not past midpoint
            if target <= end and target >= middle:
                result = self.searchSubarray(nums, midpoint, e, target)
            else:
                result = self.searchSubarray(nums, s, midpoint-1, target)
            
        elif start <= middle >= end:
            # shift, and past midpoint
            if target >= start and target <= middle:
                result = self.searchSubarray(nums, s, midpoint)
            else:
                result = self.searchSubarray(nums, midpoint+1, e, target)
        return result