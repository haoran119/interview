# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # two pointers
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if head is None or val is None:
            return None

        if head.val == val:
            return head.next

        previous_point, current_point = head, head.next
        while current_point is not None and current_point.val != val:
            previous_point, current_point = current_point, current_point.next

        if current_point is not None:
            previous_point.next = current_point.next

        return head
