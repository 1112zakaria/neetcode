/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
#include <algorithm>

#if 1
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
#endif

class Solution {
public:
    /**
     * Approach:
     * - if root is null, return 0
     * - return the max depth of the child nodes + 1
    */
    int maxDepth(Node* root) {
        int max_child = 0; // used to be undefined
        if (root == nullptr) return 0;
        for (int i=0; i<root->children.size(); i++) {
            max_child = max(max_child, maxDepth(root->children[i]));
        }
        return 1 + max_child;
    }
};
// @lc code=end

