/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
	var stack []int
	p := head
	for p != nil {
		stack = append(stack, p.Val)
		p = p.Next
	}
	var res []int
	for len(stack) != 0 {
		v := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		res = append(res, v)
	}
	return res
}

func reversePrint(head *ListNode) []int {
	if head == nil {
		return nil
	}
	return append(reversePrint(head.Next), head.Val)
}