/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

#include <ctype.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * Approach #1 (naive, O(n), O(n)):
     * - traverse linked list
     * - store each node in a set
     * - during traversal, check that the node exists in the set,
     *      return true if this is the case
     * - return false at end of traversal
     * 
     * Approach #2 (floyd's algorithm - 2 pointers, O(n), O(1)):
     * - maintain 2 pointers. ptr a travels 1 node at a time. ptr 2
     * travels 2 nodes at a time
     * - the two pointers will collide eventually if there is a cycle,
     * otherwise they will be equal to null
    */
    bool hasCycle(ListNode *head) {
        ListNode *ptrA, *ptrB;

        if (head == nullptr) {
            return false;
        }

        ptrA = head;
        ptrB = head->next;

        while (ptrA != ptrB && ptrB != nullptr) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
            if (ptrB != nullptr) {
                // i dont want nullptr dereference error
                ptrB = ptrB->next;
            }
        }
        
        if (ptrA == ptrB) {
            return true;
        }
        return false;

    }
};
// @lc code=end

