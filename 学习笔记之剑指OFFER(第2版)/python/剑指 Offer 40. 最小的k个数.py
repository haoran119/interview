class Solution:
    # sort
    def getLeastNumbers1(self, arr: List[int], k: int) -> List[int]:
        if not arr or k == 0:
            return []
        
        arr.sort()

        return arr[:k]

    # heap
    def getLeastNumbers2(self, arr: List[int], k: int) -> List[int]:
        if not arr or k == 0:
            return []
        
        # In Python, the pop method returns the smallest item, not the largest 
        # (called a “min heap” in textbooks; a “max heap” is more common in texts 
        # because of its suitability for in-place sorting).
        # So we need to use -arr[] to maintain the top k smallest nums.
        hp = [-x for x in arr[:k]]
        # Transform list x into a heap, in-place, in linear time.
        heapq.heapify(hp)

        for i in range(k, len(arr)):
            # To access the smallest item without popping it, use heap[0].
            if -hp[0] > arr[i]:
                # Pop and return the smallest item from the heap, maintaining the heap invariant.
                heapq.heappop(hp)
                # Push the value item onto the heap, maintaining the heap invariant.
                heapq.heappush(hp, -arr[i])
        
        # transform negative nums to positive
        results = [-x for x in hp]

        return results

    # quick sort partition
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not arr or k == 0:
            return []

        if k >= len(arr):
            return arr
            
        def quick_sort(nums: List[int], left: int, right: int) -> List[int]:
            # initiate base value
            i, j, temp = left, right, nums[left]

            while i < j:
                # need to scan from right first
                while i < j and nums[j] >= temp:
                    j -= 1                
                while i < j and nums[i] <= temp:
                    i += 1
                nums[i], nums[j] = nums[j], nums[i]
            
            # place base value on the correct position i
            nums[i], temp = temp, nums[i]

            if k < i:
                return quick_sort(nums, left, i - 1)
            elif k > i:
                return quick_sort(nums, i + 1, right)

            return nums[:k]
        
        return quick_sort(arr, 0, len(arr) - 1)
