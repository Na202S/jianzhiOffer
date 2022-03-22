# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = []
        p = head
        while p:
            stack.append(p.val)
            p = p.next
        res = []
        while stack:
            res.append(stack.pop())
        return res


class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if not head:
            return []
        return self.reversePrint(head.next) + [head.val]
