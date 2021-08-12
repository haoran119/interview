class Solution:
    # sorted()
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return sorted(nums, reverse=True)[k - 1]
            
    # heapq.nlargest()
    def findKthLargest2(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1]

    # Max Heap with heapq
    def findKthLargest3(self, nums: List[int], k: int) -> int:
        nums = [-num for num in nums]
        
        heapq.heapify(nums)
        
        for _ in range(k):
            result = heapq.heappop(nums)
            
        return -result    
    
    # Min Heap with heapq
    def findKthLargest4(self, nums: List[int], k: int) -> int:
        min_heap = [-float('inf')] * k
        
        # min heap with k elements
        heapq.heapify(min_heap)
        
        for num in nums:
            if num > min_heap[0]:
                heapq.heappop(min_heap)
                heapq.heappush(min_heap, num)
        
        return min_heap[0]
    
    # Divide and Conquer
    def findKthLargest5(self, nums: List[int], k: int) -> int:
        _left, _right = 0, len(nums) - 1
        
        def partition(nums, left, right):
            i, j, pivot = left, right, nums[left]
            
            while i < j:
                while i < j and nums[j] <= pivot: 
                    j -= 1
                if i < j:
                    nums[i] = nums[j]
                    i += 1
                
                while i < j and nums[i] >= pivot:
                    i += 1
                if i < j:
                    nums[j] = nums[i]
                    j -= 1
            
            nums[i] = pivot
            
            return i
        
        while True:
            pos = partition(nums, _left, _right)
            
            if pos == k - 1:
                return nums[k - 1]
            elif pos < k - 1:
                _left = pos + 1
            else:
                _right = pos - 1
