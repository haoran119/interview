"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        
        head = root
        list_current = [root]
        
        while list_current:
            next_level = []
            
            for i in range( len( list_current ) ):
                if i + 1 < len(list_current):
                    list_current[i].next = list_current[i + 1]
                
                if list_current[i].left:
                    next_level.append(list_current[i].left)
                if list_current[i].right:
                    next_level.append(list_current[i].right)
            
            list_current = next_level
        
        return head            
