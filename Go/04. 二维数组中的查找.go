func findNumberIn2DArray(matrix [][]int, target int) bool {
	/*  矩阵形式
	       小 → 大
	       ↓    ↓
	       大 → 大大
	    从左下角开始查找
	*/
	i, j := len(matrix)-1, 0
	for i >= 0 && j < len(matrix[0]) {
		if target > matrix[i][j] {
			// 目标值更大，则去掉所在列（因为这一列更小）
			j++
		} else if target < matrix[i][j] {
			// 目标值更小，则去掉所在行（因为这一行更大）
			i--
		} else {
			return true
		}
	}
	return false
}