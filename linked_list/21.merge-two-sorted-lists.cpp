/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

struct ListNode
{
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
class Solution
{
public:
    /**
     * Approaches:
     * 1. Store the nodes in a buffer and sort then link the nodes (O(nlogn) time, O(n) space)
     * 2. Iterate the two-pointers, maintain output pointer, detach and link nodes accordingly (O(n) time, O(1) space)
     * 
     * I like 2, let's go with that.
     * 
     * Steps:
     * 
     * initialization:
     *      - list1 and list2
     *      - output: merged_head, merged_curr
     * - loop list1 and list2 until either cursor is NULL, selectively adding the nodes to 
     * merged_list based on value
     * - merge remaining non-null list
     */
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *merged_head, *merged_curr;

        // nullcase
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        else if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        // Init
        merged_head = nullptr;
        merged_curr = nullptr;

        if (list1->val < list2->val)
        {
            merged_head = list1;
            list1 = list1->next;
        }
        else
        {
            merged_head = list2;
            list2 = list2->next;
        }

        merged_curr = merged_head;
        merged_curr->next = nullptr;

        // loop
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                merged_curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                merged_curr->next = list2;
                list2 = list2->next;
            }

            // Increment curr and detach added node from its original list
            merged_curr = merged_curr->next;
            merged_curr->next = nullptr;
        }

        // Update output list with remaining elements
        if (list1 != nullptr)
        {
            merged_curr->next = list1;
        }
        else if (list2 != nullptr)
        {
            merged_curr->next = list2;
        }

        return merged_head;
    }
};
// @lc code=end
