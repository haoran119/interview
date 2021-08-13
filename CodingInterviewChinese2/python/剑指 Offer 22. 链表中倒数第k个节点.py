# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # two pointers
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if head is None or k == 0:
            return None

        p_ahead, p_behind = head, head
        for _ in range(k):
            # need to check p_ahead prior to moving to the next point
            if p_ahead is None:
                return None
            p_ahead = p_ahead.next
                
        while p_ahead is not None:
            p_ahead, p_behind = p_ahead.next, p_behind.next
        
        return p_behind
