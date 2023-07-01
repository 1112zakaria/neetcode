/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <vector>
using namespace std;

// @lc code=start
class MinStack {
public:
    MinStack() {
        stack = vector<int>();
        history = vector<int>();
    }
    
    void push(int val) {
        stack.push_back(val);

        if (history.size() == 0 || history.back() >= val) {
            history.push_back(val);
        }
    }
    
    void pop() {
        if (stack.back() == history.back()) {
            history.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return history.back();
    }

private:
    vector<int> stack;
    vector<int> history;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

