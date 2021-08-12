#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};

int main ()
{
    Solution testSolution;
    bool result = false;
    
    result = testSolution.canWinNim(1);    

    cout << result << endl;
    
    char ch;
    cin >> ch;
    
    return 0;
}
