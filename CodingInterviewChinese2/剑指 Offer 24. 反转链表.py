# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # iteration
    # pay attention to the three pointers assignment
    def reverseList1(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head

        previous, current = None, head
        while current is not None:
            next = current.next
            current.next = previous
            previous = current
            current = next
        
        return previous

    # recursion
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head

        new_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None

        return new_head
