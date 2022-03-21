class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        /*  矩阵形式
            小 → 大
            ↓    ↓
            大 → 大大
         从左下角开始查找
        */
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (target > matrix[i][j]) {
                // 目标值更大，则去掉所在列（因为这一列更小）
                j++;
            } else if (target < matrix[i][j]) {
                // 目标值更小，则去掉所在行（因为这一行更大）
                i--;
            } else {
                return true;
            }
        }
        return false;
    }
};