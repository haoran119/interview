# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # recursion
    def reversePrint1(self, head: ListNode) -> List[int]:
        return (self.reversePrint(head.next) + [head.val] if head is not None
                else [])

    # extra stack
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = []
        while head is not None:
            stack.append(head.val)
            head = head.next

        # return stack reversely
        return stack[::-1]
