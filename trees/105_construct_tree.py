from typing import List, Optional

# Definition for a binary tree node
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        """
        Definitions:
            - preorder: root, left, right
            - inorder: left, root, right
        
        Rules:
            - in preorder traversal, the first value is the tree root
            - in preorder traversal, the first value after the root is the root of the
                left subtree
            - in the inorder traversal, values to the left of the root are part of the
                left subtree, values to the right of the root are part of the right
                subtree
        
        Objective:
            - given preorder and inorder traversal array, return binary tree with node
                pointers as underlying data structure
        
        Approach #1:
            1.0 For each root/subtree?,
                1.1 set first value in preorder traversal as the subtree root
                1.2 find root value index in inorder traversal list -> root_val_index
                1.3 for all values to left of root_val_index, create list consisting
                    of elements in preorder -> left_preorder
                1.4 for all values to right of root_val_index, create list consisting
                    of elements in preorder -> right_preorder
                1.5 build and set left subtree using left_preorder
                1.6 build and set right subtree using right_preorder
        
        Notes:
            - 1.3, 1.4 have high shit time complexity potential
            - looping in 1.2 could be merged with 1.3 and 1.4
        """
        # 1.0
        root = self.buildSubtree(preorder, inorder)
        return root
    
    def buildSubtree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        """
        
        """
        if preorder == []:
            return None
        # 1.1
        root_val = preorder[0]
        subtree_root = TreeNode(root_val)
        # 1.2
        for i in range(len(inorder)):
            if inorder[i] == root_val:
                root_val_index = i
        # 1.3
        left_preorder = []
        left_inorder = inorder[:root_val_index]
        for val in preorder:
            if val in left_inorder:
                left_preorder += [val]     
        # 1.4
        right_preorder = []
        right_inorder = inorder[root_val_index+1:]
        for val in preorder:
            if val in right_inorder:
                right_preorder += [val]
        # prints
        print(f"buildSubtree - preorder: {preorder}, inorder: {inorder}")
        # 1.5
        subtree_root.left = self.buildSubtree(left_preorder, inorder)
        #1.6
        subtree_root.right = self.buildSubtree(right_preorder, inorder)

        return subtree_root
        
    
if __name__ == "__main__":
    a = Solution()
    t1_preorder = [3,9,20,15,7]
    t1_inorder = [9,3,15,20,7]
    a.buildTree(t1_preorder, t1_inorder)