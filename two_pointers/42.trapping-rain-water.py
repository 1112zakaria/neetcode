#
# @lc app=leetcode id=42 lang=python3
#
# [42] Trapping Rain Water
#

# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        """
        Approach:
        - for every bar b, get the max height on the left and the max
        height on the right
        - the minimum of these two bars has to be greater than the height
        of b, and the difference is the amount of water at b
        - Q: how do I get the maximums? iterate once and cache left and right max?

        Optimization:
        - utilize two-pointers, one starting on each edge
        - keep track of max left height and max right height
        - process the pointer with the smallest max height
            - calculate water height and add
        """
        trapped_water = 0
        l_ptr, r_ptr = 0, len(height)-1
        max_left = height[l_ptr]
        max_right = height[r_ptr]

        while l_ptr < r_ptr:
            # Calculate trapped water and update max height
            if max_left <= max_right:
                l_ptr += 1
                bar_height = height[l_ptr]
                max_left = max(bar_height, max_left)
                trapped_water += max_left - bar_height
            else:
                r_ptr -= 1
                bar_height = height[r_ptr]
                max_right = max(bar_height, max_right)
                trapped_water += max_right - bar_height
        return trapped_water
        
# @lc code=end

