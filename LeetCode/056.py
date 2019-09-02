class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return None
        
        intervals.sort(key=lambda x : x[0])
        
        merged = []
        
        for interval in intervals:
            # if the merged interval list is empty or 
            # the current interval does not overlap with the previous, 
            # simply append it.
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
            # otherwise, there is overlap, so merge the current and previous intervals.
                merged[-1][1] = max(merged[-1][1], interval[1])
        
        return merged        
