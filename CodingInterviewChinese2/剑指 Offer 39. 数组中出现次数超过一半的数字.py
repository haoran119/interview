class Solution:
    # Hashmap
    def majorityElement1(self, nums: List[int]) -> int:
        # dict subclass for counting hashable objects
        counts = collections.Counter(nums)

        # Return the largest item in an iterable or the largest of two or more arguments.
        return max(counts.keys(), key = counts.get)

    # Sort
    def majorityElement2(self, nums: List[int]) -> int:
        nums.sort()

        return nums[len(nums) // 2]

    # Random
    def majorityElement3(self, nums: List[int]) -> int:
        majority_count = len(nums) // 2
        while True:
            # Return a random element from the non-empty sequence seq
            candidate = random.choice(nums)
            if sum(1 for num in nums if num == candidate) > majority_count:
                return candidate

    # Divide and conquer
    def majorityElement4(self, nums: List[int]) -> int:
        def helper(low: int, high: int) -> int:
            if low == high:
                return nums[low]

            # divide
            middle = (high - low) // 2 + low
            left = helper(low, middle)
            right = helper(middle + 1, high)

            # if the two halves agree on the majority element, return it
            if left == right:
                return left
            
            # otherwise scan and count each element
            left_count = sum(1 for i in range(low, high + 1) if nums[i] == left)
            right_count = sum(1 for i in range(low, high + 1) if nums[i] == right)

            return left if left_count > right_count else right
        
        # the arg high is len(nums) - 1
        return helper(0, len(nums) - 1)

    # Boyer-Moore 
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if candidate == num else -1)
        
        return candidate
