# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # DFS
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        if not root or target is None:
            return []

        list_result, list_path = [], []

        def dfs(node: TreeNode, sum: int):
            # pay attention that the integer could be negative
            # so that we could not cut path with sum > target
            if not node:
                return

            list_path.append(node.val)
            
            if node.left is None and node.right is None and sum == target:
                # need to use [:] to get a copy of the list
                list_result.append(list_path[:])

            if node.left:
                dfs(node.left, sum + node.left.val)
            if node.right:
                dfs(node.right, sum + node.right.val)

            list_path.pop()
        
        dfs(root, root.val)

        return list_result
