# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # 当根节点为空，或者为p、q节点时，退出递归
        if not root or root == p or root == q:
            return root
        # 在左右子树中递归
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        # 若有一个为空，则返回非空的子树根节点
        # 若左右递归均不为空，则返回根节点
        if not left:
            return right
        if not right:
            return left
        return root
