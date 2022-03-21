class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        fast = slow = head
        # fast 从头遍历链表走 k 步， slow 不动
        for i in range(k):
            fast = fast.next
        # 至此，fast 领先 slow 共 k 个节点
        # 二者同步后移
        # fast 为空时，slow 指向倒数第 k 个节点
        while fast:
            fast = fast.next
            slow = slow.next
        return slow
