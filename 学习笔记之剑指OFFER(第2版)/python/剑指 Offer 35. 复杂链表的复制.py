"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    # Linkedlist + Hash map
    def copyRandomList1(self, head: 'Node') -> 'Node':
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

    # Linkedlist + insert / split nodes
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None:
            return None
        
        current = head

        # insert a copied node after each old node
        while current is not None:
            temp = Node(x = current.val)
            temp.next = current.next
            current.next = temp
            current = temp.next
        
        current = head

        # assign copied node of current.random to random field of copied node of current
        while current is not None:
            if current.random is not None:
                current.next.random = current.random.next
            
            current = current.next.next
        
        # shallow copy
        current = result = head.next
        previous = head

        # split the old nodes and copied nodes
        while current.next is not None:
            # original next node after newly inserted node
            previous.next = previous.next.next
            # copied next node after original next node
            current.next = current.next.next

            previous = previous.next
            current = current.next
        
        # tail of the old linkedlist
        previous.next = None

        # head of the newly copied linkedlist
        return result
