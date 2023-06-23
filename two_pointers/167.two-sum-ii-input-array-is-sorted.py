#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input Array Is Sorted
#
import collections

# @lc code=start
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        """
        * Approach:
        * - keep track of map with key: int, value: int - pair map
        * - for every number i:
        *  - check that number i exists as a key in the pair map, if true
        *  return index of number i and value of the pair[i]
        *  - calculate the pair needed to match the target, k, and write
        *  pair[k] = index i
        Approach #2 (exploits sorted property):
        - start with pointer on the left and right
        - when the sum of the two ptrs is > target, move the right ptr
        - when the sum of the two ptrs is < target, move the right ptr
        - when the sum of the two ptrs == target, return [lptr, rptr]
        """
        l_ptr, r_ptr = 0, len(numbers)-1
        while numbers[l_ptr] + numbers[r_ptr] != target:
            left, right = numbers[l_ptr], numbers[r_ptr]
            local_sum = left + right
            if local_sum > target: r_ptr -= 1
            elif local_sum < target: l_ptr += 1
        return [l_ptr+1, r_ptr+1]
# @lc code=end

