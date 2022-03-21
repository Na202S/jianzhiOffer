class Solution {
   public:
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size() - 1);
    }

    // 判断数组 postorder[i:j]
    bool verify(vector<int>& postorder, int i, int j) {
        if (i >= j) {
            return true;
        }
        // 确保了 postorder[i:firstRight-1] 所有数都是比根节点的值小的
        // 这一部分就是左子树
        int id = i;
        while (postorder[id] < postorder[j]) {
            id++;
        }
        int firstRight = id;
        // 确保了 postorder[firstRight:id-1] 所有数都是比根节点的值大的
        // 这一部分就是右子树
        while (postorder[id] > postorder[j]) {
            id++;
        }
        // 检查边界是否一致，递归判断左右子数组
        return id == j && verify(postorder, i, firstRight - 1) && verify(postorder, firstRight, j - 1);
    }
};