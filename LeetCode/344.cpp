#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.length() - 1;
        char* sTemp = (char*)s.c_str();
        char temp;
        
        while (i < j)
        {
//            swap(s[i++], s[j--]);
            temp = sTemp[i];
            sTemp[i] = sTemp[j];
            sTemp[j] = temp;
            i++;
            j--;
        }
        
        return (string)sTemp;
    }
};

int main ()
{
    Solution testSolution;
    string result = testSolution.reverseString("hello");    
    
    cout << result << endl;

    char ch;
    cin >> ch;
    
    return 0;
}
