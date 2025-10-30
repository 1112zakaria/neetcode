/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

#include <iostream>

using namespace std;

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
     * 1. Utilize a stack to store all of the nodes and then re-order them accordingly (O(n) time, O(n) space)
     * 2. Utilize recursion to iterate over each of the nodes and link them to the previous node (O(n) time,
     * arguably O(n) space if you treat the stack space expansion as memory, otherwise if you're a goober you
     * can claim O(1)...
     * 3. Approach #2 but instead of recursion, iterate using a loop to save on the stack space (O(n) time, O(1) space)
     *
     * Let's go straight to approach #3.
     *
     * Steps:
     * - initialization:
     *      - curr_node, prev_node, next_node
     *      - output: reversed_head
     * - loop list until curr_node is NULL
     * - foreach:
     *      - you have curr_node, prev_node, and next_node
     *      - set reversed_head to curr_node and link its next pointer
     *      to prev_node
     *      loop increment: prev_node = curr_node, curr_node = next_node, next_node = curr_node->next
     * - return reversed_head
     *
     */
    ListNode *reverseList(ListNode *head)
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
