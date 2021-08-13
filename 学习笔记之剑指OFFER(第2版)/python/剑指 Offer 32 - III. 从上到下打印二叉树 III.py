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
        is_odd_layer = True

        while queue:
            # use deque instead of list
            current_layer = collections.deque()
            n_nodes = len(queue)

            for _ in range(n_nodes):
                node = queue.popleft()

                # different append approaches for odd/oven layer
                if is_odd_layer:
                    # append to the end
                    current_layer.append(node.val)
                else:
                    # append to the front
                    current_layer.appendleft(node.val)
                
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
            
            is_odd_layer = not is_odd_layer
            
            # convert deque into list
            list_result.append(list(current_layer))

        return list_result
