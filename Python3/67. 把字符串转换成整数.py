class Solution:
    def strToInt(self, str: str) -> int:
        n = len(str)
        index = 0
        # 1、丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
        while index < n and str[index] == ' ':
            index += 1
        if index == n:
            return 0

        # 2、当我们寻找到的第一个非空字符为正或者负号时
        sign = 1
        if str[index] == '+' or str[index] == '-':
            if str[index] == '-':
                sign = -1
            index += 1

        # 3、之后连续的数字字符组合起来，形成整数
        val = 0
        res = 0
        INT_MAX = 2**31-1
        INT_MIN = -2**31
        while index < n and '0' <= str[index] <= '9':
            val = val*10 + int(str[index])
            res = val*sign
            if res > INT_MAX:
                return INT_MAX
            if res < INT_MIN:
                return INT_MIN
            index += 1
        return res
