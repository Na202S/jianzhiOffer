class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            # 重复这个过程直到下标为 i 的位置上放的是数字 i
            while nums[i] != i:
                x = nums[i]
                # 如果下标为 x 的位置上也是 x，则找到了重复的数字
                if nums[x] == x:
                    return x
                # 否则，将数字 x 放到下标为 x 的位置上
                nums[i] = nums[x]
                nums[x] = x
        return -1
