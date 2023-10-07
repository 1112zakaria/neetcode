/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
struct Height {
    int height;
    int start_idx;
};

class Solution {
public:
    /**
     * Notes:
     * - can i use sliding window?
     * - area = min([left:right]) * (right - left + 1)
     * - i need a constant-time method of getting the minimum
     * value in the set of histogram bars
     *      - stack? heap?
     * - observation: if the
     * - goal: you want to calculate the max area starting
     * at each histogram bar and including as much width as possible
     *      - return the maximum area
     * - note:
     *      - to calculate the area, we need to keep track of where the
     *      rectangle starts, and...
     *      - 
     * 
     * Approach (stack, O(n))
     * - keep track of max area
     * - keep track of current_start
     * - keep track of max-stack of start_idx, height pairs, sorted by height
     * - foreach height:
     *      - if curr_height >= top_height,
     *          - set current_start to idx
     *      - elif:
     *          - update current_start to top of stack's start_idx
     *          - pop all elements bigger than curr_height & calculate area
     *      - add to stack
     * 
    */
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        int curr_start = 0;
        Height curr_height, top_height;
        vector<Height> height_stack; // the back is the top of the stack

        for (int i=0; i<heights.size(); i++) {

            curr_height = {heights[i], curr_start};

            if (!height_stack.empty() && curr_height.height >= height_stack.back().height) {
                curr_start = i;
            }
            
            while (!height_stack.empty() && curr_height.height < height_stack.back().height) {
                // curr height is decreasing
                top_height = height_stack.back();
                max_area = max(max_area, top_height.height * (i - top_height.start_idx));
                height_stack.pop_back();
                curr_start = top_height.start_idx;
            }
            
            curr_height.start_idx = curr_start; // override curr_start if it was updated
            height_stack.push_back(curr_height);            
        }

        // clear remaining stack values:
        int i = heights.size();
        while (!height_stack.empty()) {
            top_height = height_stack.back();
            max_area = max(max_area, top_height.height * (i - top_height.start_idx));
            height_stack.pop_back();
        }

        return max_area;
    }
};
// @lc code=end

