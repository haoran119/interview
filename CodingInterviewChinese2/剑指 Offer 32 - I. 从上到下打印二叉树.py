# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # BFS + Deque (Double-ended queue)
    def levelOrder(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        
        # Time complexity of deque.popleft() is O(1), and list.pop(0) is O(N).
        list_result, queue = [], collections.deque()
        queue.append(root)

        while queue:
            node = queue.popleft()
            list_result.append(node.val)
            
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
        
        return list_result
