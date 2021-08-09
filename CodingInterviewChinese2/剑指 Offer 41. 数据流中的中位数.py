from heapq import *

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # min heap for bigger half
        self.heap_a = []
        # max heap for smaller half
        # Python is using min heap, so need to insert negative num to implement max heap
        self.heap_b = []

    # Use two Heap to save bigger half with min heap A and smaller half with max heap B
    # len(heap_a) = len(heap_b) or len(heap_b) + 1
    # len(heap_a) = n_num / 2 or (n_num + 1) / 2
    # len(heap_b) = n_num / 2 or (n_num - 1) / 2
    def addNum(self, num: int) -> None:
        # push the biggest num from heap B to A
        # need to push num to heap B first and then pop the biggest num from B
        if len(self.heap_a) == len(self.heap_b):
            # Push item on the heap, then pop and return the smallest item from the heap. 
            # The combined action runs more efficiently than heappush() followed by a 
            # separate call to heappop().
            # need to push -num for the max heap
            heappush(self.heap_a, -heappushpop(self.heap_b, -num))
        # push the smallest num from heap A to B
        # need to push num to heap A first and then pop the smallest num from A
        else:
            # push num directly to the min heap
            heappush(self.heap_b, -heappushpop(self.heap_a, num))

    # Median = (A[0] + -B[0]) / 2 if n_num is even coz that we push -num into B for max heap
    def findMedian(self) -> float:
        # To access the smallest item without popping it, use heap[0].
        return (self.heap_a[0] if len(self.heap_a) != len(self.heap_b) 
                else (self.heap_a[0] - self.heap_b[0]) / 2.0)


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
