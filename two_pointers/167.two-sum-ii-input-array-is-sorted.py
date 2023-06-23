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
        """
        pair_map = collections.defaultdict(set)
        for i in range(len(numbers)):
            value = numbers[i]
            complement = target - value
            
            if pair_map[value] != set():
                return sorted([i+1, pair_map[value]+1])
            pair_map[complement] = i

        return None
# @lc code=end

