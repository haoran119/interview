"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    # DFS + In-order tree traversal
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if root is None:
            return

        def dfs(current: 'Node'):
            if current is None:
                return
            
            dfs(current.left)

            if self.previous is not None:
                # save the link between previous and current
                self.previous.right = current
                current.left = self.previous
            else:
                # save the head if previous is None
                self.head = current
            
            # save the current node
            self.previous = current

            dfs(current.right)
        
        self.previous = None
        dfs(root)

        # previous is the tail now
        self.head.left = self.previous
        self.previous.right = self.head

        return self.head
