# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    # Pre-order tree traversal + DFS
    def serialize1(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return ''
        
        def helper(node: 'TreeNode', s: 'str') -> 'str':
            if node is None:
                # use $ for empty nodes and leaves
                s += '$,'
            else:
                s += str(node.val) + ','
                s = helper(node.left, s)
                s = helper(node.right, s)

            return s

        return helper(root, '')

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return ''
        
        def helper(node: 'TreeNode'):
            if node is None:
                # use $ for empty nodes and leaves
                values.append('$')
            else:
                values.append(str(node.val))
                helper(node.left)
                helper(node.right)

        values = []
        helper(root)
        
        return ','.join(values)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        
        def helper() -> 'TreeNode':
            # Retrieve the next item from the iterator by calling its __next__() method
            value = next(values)

            if value == '$':
                return None
            
            node = TreeNode(int(value))
            node.left = helper()
            node.right = helper()

            return node
        
        # Return an iterator object
        # Return a list of the words in the string
        values = iter(data.split(','))

        return helper()

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
