/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
#define MAX_OPERATIONS IS_INTEGER

enum Operation {
    ADDITION=0,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    IS_INTEGER,
};

static int add(int x, int y) {
    return x + y;
}
static int subtract(int x, int y) {
    return x - y;
}
static int multiply(int x, int y) {
    return x * y;
}
static int divide(int x, int y) {
    return x / y;
}

class Solution {
public:
    /**
     * Approach #1 (DFS Recursion?, O(n)):
     * - base case: token[i] is an int
     *      - return token[i]
     * - recursive case: token[i] is an operation
     *      - return operation(process(i-1), process(i-2))
     * Approach #2 (Stack, O(n)):
     * - iterate tokens, for each token:
     *      - if integer, add to stack
     *      - if operation, pop the top two ints and push the 
     *      operation result to the stack
     * - return stack[0]
    */
    int evalRPN(vector<string>& tokens) {
        vector<int> stack = vector<int>();
        process(tokens, stack);
        return stack[0];
    }

private:
    unordered_map<Operation, int (*)(int,int)> opFuncMap = {
        {ADDITION, add},
        {SUBTRACTION, subtract}, 
        {MULTIPLICATION, multiply}, 
        {DIVISION, divide}
    };

    void process(vector<string> &tokens, vector<int> &stack) {
        string val;
        int s1, s2;
        Operation op;
        for (int i=0; i<tokens.size(); i++) {
            val = tokens[i];
            op = getOperation(val);
            if (op == IS_INTEGER) {
                stack.push_back(getNumber(val));
                continue;
            }
            s1 = stack.back();
            stack.pop_back();
            s2 = stack.back();
            stack.pop_back();
            stack.push_back(opFuncMap[op](s2, s1));
        }
    }

    int getNumber(string num) {
        return atoi(num.c_str());
    }

    Operation getOperation(string val) {
        string operations[] = {"+","-","*","/"};
        Operation ops[MAX_OPERATIONS] = {ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION};
        for (int i=0; i<MAX_OPERATIONS; i++) {
            if (val == operations[i]) {
                return ops[i];
            }
        }
        return IS_INTEGER;
    }
};
// @lc code=end

