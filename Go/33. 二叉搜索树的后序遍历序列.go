func verifyPostorder(postorder []int) bool {
	// 判断数组 postorder[i:j]
	var verify func(i, j int) bool
	verify = func(i, j int) bool {
		if i >= j {
			return true
		}
		// 确保了 postorder[i:firstRight-1] 所有数都是比根节点的值小的
		// 这一部分就是左子树
		id := i
		for postorder[id] < postorder[j] {
			id++
		}
		firstRight := id
		// 确保了 postorder[firstRight:id-1] 所有数都是比根节点的值大的
		// 这一部分就是右子树
		for postorder[id] > postorder[j] {
			id++
		}
		// 检查边界是否一致，递归判断左右子数组
		return id == j && verify(i, firstRight-1) && verify(firstRight, j-1)
	}

	return verify(0, len(postorder)-1)
}