/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

#include <cstddef>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    /**
     * Approach #1 (iterative, O(?)):
     * - Note: I need all of the nodes layer-by-layer...
     * - traverse tree, maintain list of roots and link from
     * left to right
     * - continue until list of roots is empty
    */
    Node* connect(Node* root) {
        return helper(root);
    }

private:
    Node* helper(Node* root) {
        vector<Node*> roots, children;

        if (root == nullptr) {
            return nullptr;
        }

        roots.push_back(root);

        while (!roots.empty()) {
            children = vector<Node*>();
            // link roots to each other
            for (int i=0; i<roots.size()-1; i++) {
                // FIXME: this might not be good way to loop in C++
                roots[i]->next = roots[i+1];
            }

            // add children to list
            for (Node* root : roots) {
                if (root->left) {
                    children.push_back(root->left);
                }
                if (root->right) {
                    children.push_back(root->right);
                }
            }

            // replace list of roots with list of children
            roots = children;
        }
        return root;
    }
};
// @lc code=end

