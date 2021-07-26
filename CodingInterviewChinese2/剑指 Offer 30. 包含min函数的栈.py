class MinStack:

    # use another stack to maintain the min sequence
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data_stack, self.min_stack = [], []

    def push(self, x: int) -> None:
        self.data_stack.append(x)

        # keep the top of the min_stack is the minimum
        # need to use <= in case that it is equal to the min
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    def pop(self) -> None:
        # pop the top of the min_stack if the data is popped
        if self.data_stack.pop() == self.min_stack[-1]:
            self.min_stack.pop()

    def top(self) -> int:
        if not self.data_stack:
            return None

        return self.data_stack[-1]

    def min(self) -> int:
        # remember to check empty stack
        if not self.data_stack or not self.min_stack:
            return None

        return self.min_stack[-1]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()
