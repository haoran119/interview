# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # recursion
    def buildTree1(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def helper(preorder_left: int, preorder_right: int,
                    inorder_left: int, inorder_right: int) -> TreeNode:
            if preorder_left > preorder_right:
                return None

            # first node in preorder is the root node
            preorder_root = preorder_left
            # locate root node in inorder
            inorder_root = index[preorder[preorder_root]]

            root = TreeNode(preorder[preorder_root])
            size_left_subtree = inorder_root - inorder_left
            root.left = helper(preorder_left + 1,
                                preorder_left + size_left_subtree,
                                inorder_left,
                                inorder_root - 1)
            root.right = helper(preorder_left + size_left_subtree + 1,
                                preorder_right,
                                inorder_root + 1,
                                inorder_right)

            return root

        n = len(preorder)
        # hash table to locate root in inorder quickly
        index = {element : i for i, element in enumerate(inorder)}

        return helper(0, n - 1, 0, n - 1)

    # iteration
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None

        root = TreeNode(preorder[0])
        # stack to store the root node of subtrees in preorder
        stack = [root]
        inorder_index = 0

        for i in range(1, len(preorder)):
            preorder_current = preorder[i]
            # top of stack
            node = stack[-1]

            # if top of stack, the current root node of preorder, is not equal to 
            # the current inorder node,
            # then the current preorder node is on the left subtree of the current 
            # root node of preorder
            if node.val != inorder[inorder_index]:
                node.left = TreeNode(preorder_current)
                stack.append(node.left)
            # Otherwise, the current preorder node is on the right subtree
            else:
                # pop up all left subtree nodes and root node in stack
                # the last popped up node is the root node
                while stack and stack[-1].val == inorder[inorder_index]:
                    node = stack.pop()
                    inorder_index += 1
                
                node.right = TreeNode(preorder_current)
                stack.append(node.right)
        
        return root
