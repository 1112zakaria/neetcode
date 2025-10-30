/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
     * 1. Store the nodes in a buffer and append to each other accordingly (O(n) time, O(n) space)
     * 2. Use recursion to provide the 'stack' mechanism and keep linking the current first and
     * current last nodes to each other on the merged list (O(n) time, O(n) stack space)
     * 3. Iterate the list in O(n^2) time to build the list (O(n^2) time, O(1) space)
     * ...
     * Remember during your thought-process for #2 that it would get kind of tricky at the halfway
     * point?
     * Consider perhaps splitting the initial list into two.
     * After reading the hints, approach is:
     * 4. Divide list into two, reverse the latter list, iteratively attach elements to the new
     * ordered list
     * 
     * Steps:
     * - initialization:
     *      - slow, fast ptrs for finding the start of the second sub-list
     * - execution:
     *      - get the start of the second sub-list
     *      - reverse the second sub-list
     *      - append items from both lists alternatively
     */
    void reorderList(ListNode *head)
    {
        ListNode *first_lst, *second_lst;
        ListNode *reordered_curr, *reordered_head;

        // nullcase
        if (head == nullptr)
        {
            return;
        }

        // init
        first_lst = head;
        second_lst = detachAndGetLatterSublist(head);
        second_lst = reverseList(second_lst);
        reordered_head = first_lst;
        first_lst = first_lst->next;
        reordered_head->next = nullptr;

        reordered_curr = reordered_head;

        // iteratively add elements to reordered list
        while (first_lst != nullptr && second_lst != nullptr)
        {
            // add second lst then first lst
            reordered_curr->next = second_lst;
            second_lst = second_lst->next;
            reordered_curr = reordered_curr->next;
            reordered_curr->next = first_lst;
            first_lst = first_lst->next;
            reordered_curr = reordered_curr->next;
            reordered_curr->next = nullptr;
        }

        if (first_lst != nullptr)
        {
            reordered_curr->next = first_lst;
        }
        if (second_lst != nullptr)
        {
            reordered_curr->next = second_lst;
        }

        head = reordered_head;

    }

private:
    inline ListNode *detachAndGetLatterSublist(ListNode *head)
    {
        ListNode *slow, *fast, *prev;

        slow = head;
        fast = head;
        prev = nullptr;
        while (fast != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        }
        // Detach previous node from new sublist
        prev->next = nullptr;
        return slow;
    }
    inline ListNode *reverseList(ListNode *head)
    {
        // Question: is this a C++ thing or a C thing as well?
        ListNode *curr_node, *prev_node, *next_node;
        ListNode *reversed_head;

        // nullcase
        if (head == nullptr)
        {
            return nullptr;
        }

        // init
        curr_node = head;
        prev_node = nullptr;
        next_node = curr_node->next;
        // reversed_head = curr_node;

        // loop
        while (curr_node != nullptr && curr_node->next != nullptr)
        {
            // Update output list
            reversed_head = curr_node;
            reversed_head->next = prev_node;

            // Increment pointers
            prev_node = curr_node;
            curr_node = next_node;
            next_node = curr_node->next;
        }

        // Update output list for last element
        reversed_head = curr_node;
        reversed_head->next = prev_node;
        return reversed_head;
    }
};
// @lc code=end
