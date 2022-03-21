# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 从根节点开始遍历
        cur = root
        while cur:
            # 若都小于根节点的值，则从左子树开始
            if p.val < cur.val and q.val < cur.val:
                cur = cur.left
            # 均大于，则从右子树开始
            elif p.val > cur.val and q.val > cur.val:
                cur = cur.right
            # 其他情况，则返回当前节点
            else:
                return cur
        return None
