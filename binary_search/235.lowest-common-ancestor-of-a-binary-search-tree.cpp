/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /**
     * Approach #1 (two stacks, O(n)):
     * - search node p, search node q
     * - maintain two stacks containing the traversed nodes
     * to reach each node
     * - iterate the two stacks until they are no longer equal
     * to each other; keep track of the last common node
     * 
     * Approach #2 (iterative traverse until diverge, O(?)):
     * - Q: can I do this without keeping track of two stacks?
     * - search both nodes p and nodes q?
     * - return the node where the search diverges into two different
     * directions
     * - Q: can I do this iteratively?
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *cursor_p, *cursor_q, *lca_node;

        cursor_p = root;
        cursor_q = root;

        while (cursor_p == cursor_q) {
            lca_node = cursor_p; // update last common ancestor
            traverse_bst(&cursor_p, p);
            traverse_bst(&cursor_q, q);
        }

        return lca_node;
    }

private:
    void traverse_bst(TreeNode** cursor, TreeNode* target) {
        if (cursor == nullptr || (*cursor) == nullptr) {
            return;
        }

        if (target->val < (*cursor)->val) {
            *cursor = (*cursor)->left;
        } else if (target->val > (*cursor)->val) {
            *cursor = (*cursor)->right;
        }
        return;
    }
};
// @lc code=end

