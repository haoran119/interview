class CQueue:

    def __init__(self):
        # stack to append value
        self.stack1 = []
        # stack to delete value
        self.stack2 = []


    def appendTail(self, value: int) -> None:
        self.stack1.append(value)


    def deleteHead(self) -> int:
        if (not self.stack1) and (not self.stack2):
            return -1

        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1[-1])
                self.stack1.pop()
        
        return self.stack2.pop()


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()
