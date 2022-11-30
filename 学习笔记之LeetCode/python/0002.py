# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy_head = ListNode( 0 )
        p_current = dummy_head
        carry = 0
        
        while l1 or l2:
            val = carry
            
            if l1:
                val += l1.val
                l1 = l1.next
            
            if l2:
                val += l2.val
                l2 = l2.next
            
            # carry, val = divmod( val, 10 )
            carry = val // 10
            val = val % 10
            
            p_current.next = ListNode( val ) # use next node to store current sum result, otherwise there will be an extra node of 0 on the tail 
            
            p_current = p_current.next
            
        if carry == 1:
            p_current.next = ListNode( 1 )
            
        return dummy_head.next
