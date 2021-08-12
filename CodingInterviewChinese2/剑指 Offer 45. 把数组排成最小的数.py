class Solution:
    # Sort
    # define compare function to compare joined str
    def minNumber1(self, nums: List[int]) -> str:
        if not nums:
            return ''
        
        def compare(x: str, y: str) -> int:
            s_xy, s_yx = x + y, y + x
            
            if s_xy > s_yx:
                return 1
            elif s_xy < s_yx:
                return -1
            else:
                return 0
        
        strs = [str(num) for num in nums]
        # Use functools.cmp_to_key() to convert an old-style cmp function to a key function.
        strs.sort(key=functools.cmp_to_key(compare))

        return ''.join(strs)

    # Sort
    # rewrite quick sort for string compare
    def minNumber(self, nums: List[int]) -> str:
        if not nums:
            return ''

        def quick_sort(left: int, right: int):
            if left >= right:
                return
            
            i, j, pivot = left, right, strs[left]

            while i < j:
                while strs[j] + pivot >= pivot + strs[j] and i < j:
                    j -= 1
                if i < j:
                    strs[i] = strs[j]
                    i += 1

                while strs[i] + pivot <= pivot + strs[i] and i < j:
                    i += 1
                if i < j:
                    strs[j] = strs[i]
                    j -= 1
            
            strs[i] = pivot
            
            quick_sort(left, i - 1)
            quick_sort(i + 1, right)        
    
        strs = [str(num) for num in nums]        
        quick_sort(0, len(strs) - 1)

        return ''.join(strs)
