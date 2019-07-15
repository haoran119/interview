# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:    
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        
        res = []
        cur = [root]
        from_right = False
        
        while cur:
            next_level, vals = [], []
            
            for node in cur:
                vals.append(node.val)
                
                if node.left:
                    next_level.append(node.left)

                if node.right:
                    next_level.append(node.right)
                    
            res.append(vals[::-1] if from_right else vals) # trick
            from_right = not from_right
            
            cur = next_level
        
        return res        
