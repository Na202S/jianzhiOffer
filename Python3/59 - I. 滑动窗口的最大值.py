class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        # dq 中存放的是数组下标
        dq = deque()
        for i, num in enumerate(nums):
            # 将 dq 中比当前数字更小的那些数字的下标都从后面移除
            while dq and nums[dq[-1]] < num:
                dq.pop()
            # 这样就可以使得最大的数字在 dq 头部
            dq.append(i)
            # 将已经到窗口之外的数字下标从 dq 前面移除
            if dq[0] <= i - k:
                dq.popleft()
            # 当 i 从 k-1 开始时，每新入一个 i，则弹出队首元素到答案中
            if i >= k - 1:
                res.append(nums[dq[0]])
        return res
