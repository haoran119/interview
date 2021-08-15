#include <iostream>
using namespace std;
 
class Solution 
{
public:
    int  NumberOf1(int n)
    {       
        cout << "Entry int  NumberOf1(int n)\n" << endl;

        if (n == 0) return 0;
        
        int count = 0;
        
        while (n != 0)
        {
              n = n & (n - 1);
              count ++;
        }
        
        return count;
    }
};

int main ()
{
    Solution testSolution;
    int n = 10;
        
    for (int i = 0; i < n; i ++)
        cout << testSolution.NumberOf1(i) << endl;
        
    getchar();
    
    return 0;
}
