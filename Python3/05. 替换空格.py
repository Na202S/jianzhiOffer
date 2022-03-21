class Solution:
    def replaceSpace(self, s: str) -> str:
        # Python中, 字符串为不可变类型
        # 所以不存在 O(1) 空间复杂度的解法
        return s.replace(' ', '%20')
