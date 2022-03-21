class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.maxHeap = []
        self.minHeap = []

    def addNum(self, num: int) -> None:
        # 为了使数据平均分配到两堆：若两堆的数据数目相等，就让 minHeap 的元素个数多1
        # 具体做法分两步：
        # 1、将新元素加入到 maxHeap；
        # 2、将 maxHeap 的堆顶元素加入到 minHeap
        # Python中默认为最小堆，使用最大堆的方法参考40
        if len(self.maxHeap) == len(self.minHeap):
            heappush(self.minHeap, -heappushpop(self.maxHeap, -num))
        else:
            heappush(self.maxHeap, -heappushpop(self.minHeap, num))

    def findMedian(self) -> float:
        if len(self.maxHeap) == len(self.minHeap):
            return (self.minHeap[0]-self.maxHeap[0])/2.0
        else:
            return self.minHeap[0]
