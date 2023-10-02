/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
struct greater1 {
    bool operator()(ListNode *lhs, ListNode *rhs) const {
        // assumes both values are != null?
        if (lhs == nullptr && rhs == nullptr) {
            return true;
        }
        if (lhs == nullptr) {
            return true;
        }
        if (rhs == nullptr) {
            return false;
        }
        return lhs->val > rhs->val;
    }
};
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
     * Approach (heap, O(nlogn)):
     * - maintain heap of all the lists, using the front value as the
     * comparison value
     * - keep popping the value and adjusting the heap until heap is empty
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* output_head = nullptr;
        ListNode* output_curr;
        ListNode* curr_node;

        make_heap(lists.begin(), lists.end(), greater1());

        while (lists.size() > 0 && lists.front() != nullptr) {
            // keep popping from heap while elements exist
            curr_node = lists.front();

            if (output_head == nullptr) {
                // initialize first value?
                output_head = new ListNode(curr_node->val);
                output_curr = output_head;
            } else {
                output_curr->next = new ListNode(curr_node->val);
                output_curr = output_curr->next;
            }
            // pop heap
            pop_heap(lists.begin(), lists.end(), greater1());
            // shift list pointer
            lists.back() = lists.back()->next;
            // if list ptr is null, remove from lists
            if (lists.back() == nullptr) {
                lists.pop_back();
            } else {
                // make heap if last element is non-null
                push_heap(lists.begin(), lists.end(), greater1());
            }
        }
        return output_head;
    }
};
// @lc code=end

