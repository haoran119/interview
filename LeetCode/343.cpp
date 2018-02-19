#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int product = 1;
        while (n > 4)
        {
              n -= 3;
              product *= 3;              
        }
        product *= n;
                
        return product;
    }
};

int main ()
{
    Solution testSolution;
    int result;
    
    result = testSolution.integerBreak(5);    
    cout << result << endl;
    
    char ch;
    cin >> ch;
    
    return 0;
}
