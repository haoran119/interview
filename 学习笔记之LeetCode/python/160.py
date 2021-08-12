# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        
        if headA is None or headB is None:
            return None
        
        pA, pB = headA, headB
        
        # if pA meets pB return the common node,
        # otherwise both reach the tail and return None
        while pA != pB:
            # counteract the difference of length with switching head nodes
            pA = headB if pA is None else pA.next
            pB = headA if pB is None else pB.next
            
        return pA
