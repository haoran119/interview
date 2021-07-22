# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # recursion
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        result = False
        
        def is_sub_tree(tree1: TreeNode, tree2: TreeNode) -> bool:
            # check True condition first as the exit condition in case that both are None
            if tree2 is None:
                return True

            if tree1 is None:
                return False

            if tree1.val != tree2.val:
                return False

            return is_sub_tree(tree1.left, tree2.left) and is_sub_tree(tree1.right, tree2.right)

        # empty tree is not sub structure of any tree
        if A is not None and B is not None:
            if A.val == B.val:
                result = is_sub_tree(A, B)

            if not result:
                result = self.isSubStructure(A.left, B)
            
            if not result:
                result = self.isSubStructure(A.right, B)
        
        return result
