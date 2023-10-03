/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /**
     * Approach (recursive, O(n))
     * - helper:
     *      - swap the two nodes
     *      - call helper recursively on the 3rd node and set as next
     *      for 2nd node
    */
    ListNode* swapPairs(ListNode* head) {
        return helper(head);
    }

private:
    ListNode* helper(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        
        ListNode *firstNode, *secondNode, *thirdNode;

        firstNode = head;
        secondNode = firstNode->next;
        thirdNode = secondNode->next;

        secondNode->next = firstNode;
        firstNode->next = helper(thirdNode);
        return secondNode;
    }

};
// @lc code=end

