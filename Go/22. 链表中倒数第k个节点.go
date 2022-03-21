func getKthFromEnd(head *ListNode, k int) *ListNode {
	fast := head
	slow := head
	// fast 从头遍历链表走 k 步， slow 不动
	for i := 0; i < k; i++ {
		fast = fast.Next
	}
	// 至此，fast 领先 slow 共 k 个节点
	// 二者同步后移
	// fast 为空时，slow 指向倒数第 k 个节点
	for fast != nil {
		fast = fast.Next
		slow = slow.Next
	}
	return slow
}