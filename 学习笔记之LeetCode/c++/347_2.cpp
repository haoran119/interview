#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <queue>
//#include <unordered_map> 
using namespace std;

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
//        unordered_map<int, int>                     frequencyMap;
          map<int, int>      frequencyMap;
          map<int, int>::const_iterator      mapCIt;
          vector<int>::const_iterator         vecCIt;
                  
//        for (const auto &num : nums)      
//            frequencyMap[num] ++;

          for (vecCIt = nums.begin(); vecCIt != nums.end(); vecCIt ++)
              frequencyMap[*vecCIt] ++;

        // 2-d vector based on frequency including frequecy 0
        vector< vector<int> >       buckets(nums.size() + 1);
        vector<int>::const_iterator           vecVCIt;

        // Pay attention to .first/.second rather than ->first/->second
//        for (auto mapCIt : frequencyMap)
//            buckets[mapCIt.second].push_back(mapCIt.first);            
            
        // Numbers with the same frequency will be pushed back to the same buckets[i]
        for (mapCIt = frequencyMap.begin(); mapCIt != frequencyMap.end(); mapCIt ++)
            buckets[mapCIt->second].push_back(mapCIt->first);            

        vector<int>  res;
/*        
        for (int i = buckets.size() - 1; i >= 0 && res.size() < k; i --)
        {
            for (int num : buckets[i])
            {
                res.push_back(num);
                if (res.size() == k)
                   break;
            }            
        }
*/

        // Find k numbers from the end of buckets to the front
        for (int i = buckets.size() - 1; i >= 0 && res.size() < k; i --)
        {
            // Find the numbers in the same buckets[frequency]
            for (vecVCIt = buckets[i].begin(); vecVCIt != buckets[i].end(); vecVCIt ++)
            {
                res.push_back(*vecVCIt);
                if (res.size() == k)
                   break;
            }            
        }
            
        return res;
    }
};

int main ()
{
    Solution testSolution;
    int arrRes[] = {1, 1, 1, 2, 2, 3};
//    vector<int> result{ {1, 1, 1, 2, 2, 3} };
      vector<int> result(arrRes, arrRes + 6);
      vector<int>::const_iterator         vecCIt;
      
    result = testSolution.topKFrequent(result, 2);
    
    for (vecCIt = result.begin(); vecCIt != result.end(); vecCIt ++)
        cout << *vecCIt << endl;
        
    getchar();
    
    return 0;
}
