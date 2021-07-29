"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    # Linkedlist + Hash
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None:
            return None

        # hash map {old node : newly copied node}
        dictionary = {}

        current = head
        # iterate linkedlist and update hash map
        while current is not None:
            dictionary[current] = Node(x = current.val)
            
            current = current.next
        
        current = head
        # iterate linkedlist and update next/random with hash map
        while current is not None:
            dictionary[current].next = dictionary.get(current.next)
            dictionary[current].random = dictionary.get(current.random)
            
            current = current.next
        
        # head in dictionary
        return dictionary[head]

