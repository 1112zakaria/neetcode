#
# @lc app=leetcode id=230 lang=python3
#
# [230] Kth Smallest Element in a BST
#

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
        Approach #1 (Recursive, O(nlogn)):
        - keep track of empty array
        - traverse the binary search tree using recursion
        - foreach element, add to array
        - at the end of the traversal, sort the array
        - access the kth element in the sorted array

        Approach #2 (Recursive inorder traversal, O(n))
        - Note: use inorder traversal to traverse in non-decreasing order
        - traverse bst inorder
        - store each node in list
        - return k-1th element
        """
        elements = []
        self.helper2(root, elements)
        #elements.sort()
        return elements[k-1]

    def helper(self, root: Optional[TreeNode], elements: list):
        if root is None:
            return
        elements.append(root.val)
        self.helper(root.left, elements)
        self.helper(root.right, elements)
        return
    
    def helper2(self, root: TreeNode, elements: list):
        if root is None:
            return
        self.helper2(root.left, elements)
        elements.append(root.val)
        self.helper2(root.right, elements)
        return


# @lc code=end

