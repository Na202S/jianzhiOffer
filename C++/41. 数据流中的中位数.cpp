class MedianFinder {
   public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        // 为了使数据平均分配到两堆：
        // 一、若两堆的数据数目相等，则让 minHeap 的元素个数 + 1
        if (maxHeap.size() == minHeap.size()) {
            // 1、将新元素加入到 maxHeap；
            maxHeap.push(num);
            // 2、将 maxHeap 的堆顶元素加入到 minHeap
            minHeap.push(maxHeap.top());
            // 3、弹出 maxHeap 的堆顶元素
            maxHeap.pop();
        } else {
            // 二、若不相等，则让 maxHeap 的元素个数 + 1
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return minHeap.top();
    }

   private:
    // C++中优先队列默认为“最大”堆：
    // 元素按照 compare 给出的函数排序，“最大”（即最后面）的元素放到堆顶
    priority_queue<int, vector<int>, less<int>> maxHeap;     // maxHeap 放较小的一半数字
    priority_queue<int, vector<int>, greater<int>> minHeap;  // minHeap 放较大的一半数字
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */