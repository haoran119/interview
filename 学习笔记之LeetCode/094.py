# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def helper(self, node: TreeNode, list_result: List[int]):
        if node is None:
            return
        
        self.helper(node.left, list_result)

        list_result.append(node.val)
        
        self.helper(node.right, list_result)
        
    # Recursive approach    
    def inorderTraversal1(self, root: TreeNode) -> List[int]:
        if root is None:
            return [] # should return [] rather than None
        
        res = []
        self.helper(root, res)
        
        return res        
    
    # Iterative approach
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        cur = root
        res, stack = [], []
        
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
                
            cur = stack.pop()
            res.append(cur.val)
            
            cur = cur.right
            
        return res
