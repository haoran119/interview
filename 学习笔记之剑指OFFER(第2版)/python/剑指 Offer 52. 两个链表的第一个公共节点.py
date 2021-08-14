# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # Linklist
    # Time O(m + n) / Space O(1)
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return
        
        pointerA, pointerB = headA, headB

        # if no intersection, pointers will both reach at the tail after m + n steps
        while pointerA != pointerB:
            # swap head node if reach the tail
            pointerA = pointerA.next if pointerA is not None else headB
            pointerB = pointerB.next if pointerB is not None else headA
        
        return pointerA
