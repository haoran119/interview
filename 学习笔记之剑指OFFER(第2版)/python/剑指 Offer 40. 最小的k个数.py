class Solution:
    # sort
    # Time O(NlogN) / Space O(logN)
    def getLeastNumbers1(self, arr: List[int], k: int) -> List[int]:
        if not arr or k == 0:
            return []
        
        arr.sort()

        return arr[:k]

    # heap
    # Time O(NlogK) / Space O(K)
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
    # We don't need the smallest k nums returned in order so we could just return the partition with 
    # smallest k nums.
    # Time O(N) / Space O(logN)
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not arr or k == 0:
            return []

        if k >= len(arr):
            return arr
            
        # search and return the smallest k nums
        def quick_sort(nums: List[int], left: int, right: int) -> List[int]:
            # initiation and use nums[left] as base value
            i, j = left, right

            while i < j:
                # need to scan from right first
                while i < j and nums[j] >= nums[left]:
                    j -= 1                
                while i < j and nums[i] <= nums[left]:
                    i += 1
                nums[i], nums[j] = nums[j], nums[i]
            
            # place base value on the correct position i
            # need to use nums[left] rather than temp to swap two num in list
            nums[i], nums[left] = nums[left], nums[i]

            # k resides on the left partition
            if k < i:
                return quick_sort(nums, left, i - 1)
            # k redides on the right partition
            elif k > i:
                return quick_sort(nums, i + 1, right)

            # base value is the (k+1)th smallest num now
            # return its left k nums
            return nums[:k]
        
        return quick_sort(arr, 0, len(arr) - 1)
