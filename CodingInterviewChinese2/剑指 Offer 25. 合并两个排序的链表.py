# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # recursion
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None:
            return l1

        p_head = None
        if l1.val < l2.val:
            p_head = l1
            p_head.next = self.mergeTwoLists(l1.next, l2)
        else:
            p_head = l2
            p_head.next = self.mergeTwoLists(l1, l2.next)

        return p_head

    # iteration
    def mergeTwoLists1(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None:
            return l1

        p_head = None
        current_l1, current_l2 = l1, l2
        if current_l1.val < current_l2.val:
            p_head = current_l1
            current_l1 = current_l1.next
        else:
            p_head = current_l2
            current_l2 = current_l2.next

        # remember to reserve the head
        p_result_head = p_head

        while current_l1 is not None and current_l2 is not None:
            if current_l1.val < current_l2.val:
                p_head.next = current_l1
                current_l1 = current_l1.next
            else:
                p_head.next = current_l2
                current_l2 = current_l2.next
            # remember to move to the next
            p_head = p_head.next
        
        # merge the remaining list
        if current_l1 is not None:
            p_head.next = current_l1
        elif current_l2 is not None:
            p_head.next = current_l2
        else:
            p_head.next = None

        return p_result_head
