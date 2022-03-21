class CQueue:

    def __init__(self):
        self.inStack = []
        self.outStack = []

    # 入队：直接添加
    def appendTail(self, value: int) -> None:
        self.inStack.append(value)

    #  出队
    def deleteHead(self) -> int:
        # 若 outStack 为空，先将 inStack 的元素搬运过来
        if not self.outStack:
            while self.inStack:
                self.outStack.append(self.inStack.pop())
        # 再次检查 outStack 是否为空
        return self.outStack.pop() if self.outStack else -1
