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
        """
        trapped_water = 0
        left_max_heights = [0 for i in range(len(height))]
        right_max_heights = [0 for i in range(len(height))]
        l_ptr, r_ptr = 1, len(height)-2
        while l_ptr < len(height):
            # Calculate left and right max height for each bar
            left_max_heights[l_ptr] = max(height[l_ptr-1], left_max_heights[l_ptr-1])
            right_max_heights[r_ptr] = max(height[r_ptr+1], right_max_heights[r_ptr+1])
            l_ptr += 1
            r_ptr -= 1
        
        for i in range(len(height)):
            local_max_height = min(left_max_heights[i], right_max_heights[i])
            bar_height = height[i]
            if local_max_height > bar_height:
                trapped_water += local_max_height - bar_height
        
        return trapped_water
        
# @lc code=end

