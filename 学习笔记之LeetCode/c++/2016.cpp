class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        auto result {0}, prev {numeric_limits<int>::max()};
        
        for (const auto i : nums) {
            result = max(result, i - prev);
            prev = min(prev, i);            
        }
        
        // result shouldn't be 0 as nums[i] < nums[j]
        return (result != 0) ? result : -1;        
    }
