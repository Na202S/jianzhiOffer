class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:

        # 判断数组postorder[i:j]
        def verify(i, j):
            if i >= j:
                return True
            index = i
            # 确保了postorder[i:right-1]所有数都是比根节点的值小的
            # 这一部分就是左子树
            while postorder[index] < postorder[j]:
                index += 1
            right = index
            # 检查剩余部分元素是否都比根节点的值大
            while postorder[index] > postorder[j]:
                index += 1
            return index == j and verify(i, right-1) and verify(right, j-1)

        return verify(0, len(postorder)-1)
