#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) 
    {
                vector<int> res(num + 1, 0);
                
                for (int i = 0; i < res.size(); i ++)
                {
                    res[i] = res[i / 2] + i % 2;                    
                }        
                
                return res;
    }
};

int main ()
{
    Solution testSolution;
    vector<int> result(5, 0);
    
    result = testSolution.countBits(5);    

    for (int i = 0; i < result.size(); i ++)
        cout << result[i] << endl;

    char ch;
    cin >> ch;
    
    return 0;
}
