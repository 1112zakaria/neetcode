from turtle import right


class Solution:
    def maxArea(self, height: List[int]) -> int:
        """
        Approach:
            - start at both edges
            - calculate area and compare with max area
            - shift smallest pointer inward, if equal, shift left ptr
            - repeat until pointers meet
            - return max area
        """
        max_area = 0
        left_ptr, right_ptr = 0, len(height) - 1

        while left_ptr < right_ptr:
            # calculate area
            left_height, right_height = height[left_ptr], height[right_ptr]
            width = right_ptr - left_ptr
            area = min(left_height, right_height) * width
            max_area = max(max_area, area)
            if right_height < left_height:
                right_ptr -= 1
            else:
                left_ptr += 1

        return max_area