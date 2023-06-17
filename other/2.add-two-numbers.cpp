/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

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

#include <stdlib.h>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    /**
     * Approach #1:
     * - construct int for l1 and l2 then get sum
     * - construct linked list for output
     * Approach #2:
     * - for each list element, calculate the sum and keep
     * track of the carry
     * - add the next linked list node using the sum result
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum, s;
        ListNode *head = nullptr, *curr;

        curr = head;

        while (l1 != nullptr || l2 != nullptr || carry == 1) {
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry == 1) {
                sum += 1;
            }

            carry = (sum > 9) ? 1 : 0;
            sum %= 10;
            // Create node and add to LL
            if (head == nullptr) {
                head = new ListNode(sum);
                curr = head;
            } else {
                curr->next = new ListNode(sum);
                curr = curr->next;
            }
        }
        return head;
    }
};
// @lc code=end

