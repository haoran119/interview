# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # BFS + Deque (Double-ended queue)
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        # Time complexity of deque.popleft() is O(1), and list.pop(0) is O(N).
        list_result, queue = [], collections.deque()
        queue.append(root)

        while queue:
            current_layer = []
            n_nodes = len(queue)

            for _ in range(n_nodes):
                node = queue.popleft()
                current_layer.append(node.val)

                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
            
            list_result.append(current_layer)
        
        return list_result
