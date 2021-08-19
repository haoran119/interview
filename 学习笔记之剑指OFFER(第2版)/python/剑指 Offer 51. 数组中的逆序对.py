class Solution:
    # Merge sort
    # Divide into two sublists and then merge them into one sorted list
    # When merging sublists, given that nums[i:middle+1], nums[j:right+1] are in ascending order,
    # nums[i:middle+1] are all greater than nums[j] if nums[i] > nums[j]
    # So the reverse pairs count = middle - i + 1 for nums[i:middle+1] and nums[j]
    # Time O(NlogN) / Space O(N)
    def reversePairs(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        def merge_sort(left: int, right: int):
            if left < right:
                # divide into two lists and sort them recursively
                middle = ((right - left) >> 1) + left
                merge_sort(left, middle)
                merge_sort(middle + 1, right)
                # merge two sorted sublists into one sorted list
                merge_array(left, middle, right)

        def merge_array(left: int, middle: int, right: int):
            # initiate temp list to store num
            list_temp = [0] * (right - left + 1)
            index = 0
            # two pointers for left and right part
            i, j = left, middle + 1

            while i <= middle and j <= right:
                if nums[i] <= nums[j]:
                    list_temp[index] = nums[i]
                    index += 1
                    i += 1
                else:
                    # count the reverse pair
                    # Given that nums[i:middle] is in ascending order,
                    # nums[i:middle] are all greater than nums[j] if nums[i] > nums[j]
                    self.count += (middle - i + 1)
                    list_temp[index] = nums[j]
                    index += 1
                    j += 1
            
            # add left remaining nums into list
            while i <= middle:
                list_temp[index] = nums[i]
                index += 1
                i += 1
            
            # add right remaining nums into list
            while j <= right:
                list_temp[index] = nums[j]
                index += 1
                j += 1
            
            # override nums with temp list
            for k in range(len(list_temp)):
                nums[left + k] = list_temp[k]
            
        # count reverse pairs
        self.count = 0
        merge_sort(0, len(nums) - 1)

        return self.count
