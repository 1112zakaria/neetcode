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
     * Approach #1 (DFS Stack Recursion?, O(n)):
     * - base case: token[i] is an int
     *      - return token[i]
     * - recursive case: token[i] is an operation
     *      - return operation(process(i-1), process(i-2))
     * - 
    */
    int evalRPN(vector<string>& tokens) {
        return process(tokens, tokens.size()-1);
    }

private:
    unordered_map<Operation, int (*)(int,int)> opFuncMap = {
        {ADDITION, add},
        {SUBTRACTION, subtract}, 
        {MULTIPLICATION, multiply}, 
        {DIVISION, divide}
    };

    int process(vector<string> &tokens, int pos) {
        string val = tokens[pos];
        Operation op = getOperation(val);
        int nextArg1, nextArg2;
        if (op == IS_INTEGER) {
            return getNumber(val);
        }
        return opFuncMap[op]( process(tokens, pos-2), process(tokens, pos-1) );
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

