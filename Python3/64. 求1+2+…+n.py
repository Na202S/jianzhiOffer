class Solution:
    def sumNums(self, n: int) -> int:
        # 在 Python 中
        # 若 and 计算结果为真，返回最后一个表达式的值
        # 若 or 计算结果为真，返回第一个结果为真的表达式的值
        # 利用 and 的短路规则，前面为假，后面就不会执行
        return n and self.sumNums(n - 1) + n
