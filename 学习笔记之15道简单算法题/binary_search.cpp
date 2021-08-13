#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
 
class Solution 
{
public:
    int binarySearch(vector<int> array, int target)
    {
        vector<int>::iterator     vecBIT = array.begin();
        vector<int>::iterator     vecEIT = array.end();
        vector<int>::iterator     vecIT = vecBIT + (vecEIT - vecBIT) / 2;
        
        while (vecBIT <= vecEIT)  
        {
              if (*vecIT == target)
                  return distance(array.begin(), vecIT); // Return distance between iterators
              else if (*vecIT < target)
              {                   
                  vecBIT = vecIT + 1;
                  vecIT = vecBIT + (vecEIT - vecBIT) / 2;
              } 
              else
              {
                  vecEIT = vecIT - 1;
                  vecIT = vecBIT + (vecEIT - vecBIT) / 2;
              }
        }
        
        if (vecBIT > vecEIT) return -1;
    }

    int binarySearchRecursion(vector<int> array, int vecBIT, int vecEIT, int target)
    {       
//        cout << "Entry int binarySearchRecursion(vector<int> array, vector<int>::iterator vecBIT, vector<int>::iterator vecEIT, int target)\n" << endl;
        
        if (vecBIT <= vecEIT)  
        {
            int    vecIT = vecBIT + (vecEIT - vecBIT) / 2;
            
            if (array[vecIT] == target)
              return vecIT;
            else if (array[vecIT] < target)
              return binarySearchRecursion(array, vecIT + 1, vecEIT, target);
            else
              return binarySearchRecursion(array, vecBIT, vecIT - 1, target);
        } 
        else
            return -1;
    }
};

int main ()
{
    Solution testSolution;
    int n = 3;
    vector<int> searchArray(1); // initialize vector of n elements with 0
    
    // push_back another n - 1 elements
    for (int i = 1; i < n; i ++)
        searchArray.push_back(i);
        
    // n element in vector now
    for (vector<int>::const_iterator vecIT = searchArray.begin(); vecIT < searchArray.end(); vecIT ++)
        cout << *vecIT << endl;
    cout << endl;
    
    cout << distance(searchArray.begin(), searchArray.end()) << "\n" << endl;
    
    for (int i = 0; i <= n; i ++)
    {
        cout << testSolution.binarySearch(searchArray, i) << endl;
        cout << testSolution.binarySearchRecursion(searchArray, 0, n, i) << endl;
    }
            
    getchar();
    
    return 0;
}
