class Solution:
    def minArray(self, numbers: List[int]) -> int:
        if not numbers:
            return None

        low, high = 0, len(numbers) - 1
        while low < high:
            pivot = low + (high - low) // 2
            # min element on the left part
            if numbers[pivot] < numbers[high]:
                high = pivot
            # min element on the right part
            elif numbers[pivot] > numbers[high]:
                low = pivot + 1
            # if duplicate elements found, skip the rightmost one
            else:
                high -= 1
            
        return numbers[low]
