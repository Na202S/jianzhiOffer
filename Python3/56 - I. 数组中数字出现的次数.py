class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        # 假设所求数字为 m 和 n
        # 所有数字异或，得到 res = m^n
        res = 0
        for num in nums:
            res ^= num
        # 查找到 m^n 中最右边的1
        # 即 m 和 n 不一样的最低位
        div = 1
        while div & res == 0:
            div <<= 1
        # 依照这一位的值分成两个子数组并且计算异或结果
        # 最终留下的数字即为只出现一次的数字
        m, n = 0, 0
        for num in nums:
            if num & div:
                m ^= num
            else:
                n ^= num
        return [m, n]
