class Solution:
    # Simulation + Stack
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if not pushed and not popped:
            return True

        stack, popped_index = [], 0

        for num in pushed:
            # pushed into stack
            stack.append(num)

            # pop out
            while stack and stack[-1] == popped[popped_index]:
                stack.pop()
                popped_index += 1
        
        return not stack
