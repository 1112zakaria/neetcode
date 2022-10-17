# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Iterative Approach:
            - for each node, set the current list to be the next pointer for the
            new node
        """
        return self.reverseListIterative(head)
        
    def reverseListIterative(self, head):
        curr_list = None
        curr_node = head

        while curr_node is not None:
            if curr_list is None:
                # set first node in list to first node copy
                curr_list = ListNode(curr_node.val)
            else:
                # put current node copy in front of current list
                new_head = ListNode(curr_node.val)
                new_head.next = curr_list
                # set current node as head
                curr_list = new_head

                # Increment node pointer
            curr_node = curr_node.next
        return curr_list
                    

        