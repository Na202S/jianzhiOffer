/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	var tmp, prev, cur *ListNode = nil, nil, head
	for cur != nil {
		tmp = cur.Next
		cur.Next = prev
		prev = cur
		cur = tmp
	}
	return prev
}