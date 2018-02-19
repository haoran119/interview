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
          vector<int>::const_iterator         vecCIt;
                  
//        for (const auto &num : nums)      
//            frequencyMap[num] ++;

          for (vecCIt = nums.begin(); vecCIt != nums.end(); vecCIt ++)
              frequencyMap[*vecCIt] ++;
        
        vector<int>  res;        
        // pair<first, second> : first is number, second is frequency
        // space is required between > and >
        priority_queue< pair<int, int> >   pq;
        map<int, int>::const_iterator      mapCIt;

/*              
        for (const auto &it : frequencyMap)
        {
            pq.push( make_pair(it.second, it.first) );
            
            if (pq.size() > (frequencyMap.size() - k))
            {
               res.push_back(pq.top().second);
               pq.pop();
            }            
        }
*/
            
        for (mapCIt = frequencyMap.begin(); mapCIt != frequencyMap.end(); mapCIt ++)
        {
            pq.push( make_pair(mapCIt->second, mapCIt->first) );
            
            if ( pq.size() > (frequencyMap.size() - k) )
            {
               res.push_back(pq.top().second);
               pq.pop();
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
