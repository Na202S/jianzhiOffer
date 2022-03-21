class CQueue {
   public:
    CQueue() {
    }

    // 入队：直接添加
    void appendTail(int value) {
        inStack.push(value);
    }

    // 出队
    int deleteHead() {
        // 若为空，先将 inStack 的元素搬运过来
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        // 再次检查 outStack 是否为空
        if (outStack.empty()) {
            return -1;
        } else {
            int res = outStack.top();
            outStack.pop();
            return res;
        }
    }

   private:
    stack<int> inStack;   // 负责入
    stack<int> outStack;  // 负责出
};