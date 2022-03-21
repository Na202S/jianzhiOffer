/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 构建哈希表方便查找
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, inorder, inorderIndex, 0, 0, inorder.size() - 1);
    }
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder,
                    const unordered_map<int, int>& index,
                    int preRootID, int inLeft, int inRight) {
        if (inLeft > inRight) {
            return NULL;
        }
        // 从 preorder 获取根节点的值
        int rootVal = preorder[preRootID];
        TreeNode* root = new TreeNode(rootVal);
        // 在 inorder 中查找根节点的下标
        int inRootID = index.find(rootVal)->second;
        // 计算左子树的大小
        int leftSize = inRootID - inLeft;
        // preorder: [root] [left] [right]
        // inorder:  [left] [root] [right]
        root->left = build(preorder, inorder, index, preRootID + 1, inLeft, inRootID - 1);
        root->right = build(preorder, inorder, index, preRootID + leftSize + 1, inRootID + 1, inRight);
        return root;
    }
};