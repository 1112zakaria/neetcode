# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """
        Approach:
            - iterate while list1 and list2 curr ptrs are not none
            - keep appending the smallest node to the list
            - append the remainding nodes in one of the non-empty lists
        """
        merged_list_head = None
        list_curr = None
        list1_ptr, list2_ptr = list1, list2

        while list1_ptr and list2_ptr:
            new_node = None
            if list1_ptr.val < list2_ptr.val:
                new_node = ListNode(list1_ptr.val)
                list1_ptr = list1_ptr.next
            else:
                new_node = ListNode(list2_ptr.val)
                list2_ptr = list2_ptr.next
            
            if merged_list_head is None:
                merged_list_head = new_node
                list_curr = merged_list_head
            else:
                list_curr.next = new_node
                list_curr = list_curr.next
        
        if list1_ptr and merged_list_head:
            # remaining list 1 nodes exist, append
            list_curr.next = list1_ptr
        else: merged_list_head = list1_ptr
        
        if list2_ptr and merged_list_head:
            # remaining list 2 nodes exist, append
            list_curr.next = list2_ptr
        else: merged_list_head = list2_ptr
            
        return merged_list_head