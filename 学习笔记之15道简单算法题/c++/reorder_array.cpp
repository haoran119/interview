#include <iostream>
#include <vector>
using namespace std;
 
class Solution 
{
public:
    void reOrderArray(vector<int> &array)
    {       
        cout << "Entry void reOrderArray(vector<int> &array)\n" << endl;
        
        vector<int> vecEven; // Store even
        
        for (vector<int>::iterator vecIT = array.begin(); vecIT != array.end(); )
            if ((*vecIT % 2) == 0)
            {
                         vecEven.push_back(*vecIT);
                         vecIT = array.erase(vecIT);
            }
            else
                vecIT ++;                         
                
        for (vector<int>::const_iterator vecCIT = vecEven.begin(); vecCIT != vecEven.end(); vecCIT ++)
            array.push_back(*vecCIT);            
    }
};

int main ()
{
    Solution testSolution;
    int array[] = {0, 1, 5, 9, 2, 6, 7, 8, 3, 4};
    vector<int> vecArray(array, array + 10);
        
    for (vector<int>::const_iterator vecCIT = vecArray.begin(); vecCIT != vecArray.end(); vecCIT ++)
        cout << *vecCIT << endl;
    cout << endl;

    testSolution.reOrderArray(vecArray);
        
    for (vector<int>::const_iterator vecCIT = vecArray.begin(); vecCIT != vecArray.end(); vecCIT ++)
        cout << *vecCIT << endl;
    cout << endl;
        
    getchar();
    
    return 0;
}
