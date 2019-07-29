# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest1(self, root: TreeNode, k: int) -> int:
        def inorder(r):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else [] # pythonic style
        
        return inorder(root)[k - 1]     
    
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []
        
        while True:
            while root:
                stack.append(root)
                root = root.left
            
            root = stack.pop()
            k -= 1
            
            if not k:
                return root.val
            
            root = root.right
