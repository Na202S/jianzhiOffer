class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        """
            矩阵形式
            小 → 大
            ↓    ↓
            大 → 大大
         从左下角开始查找
        """
        i, j = len(matrix) - 1, 0
        while i >= 0 and j < len(matrix[0]):
            # 目标值更大，则去掉所在列（因为这一列更小）
            if target > matrix[i][j]:
                j += 1
            # 目标值更小，则去掉所在行（因为这一行更大）
            elif target < matrix[i][j]:
                i -= 1
            else:
                return True
        return False
