#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int substr(const string source, const string sub)
    {
        // Corner case
        if (sub.empty()) return 0;
        if (source.empty()) return -1;
                
        int n = source.length() - sub.length() + 1;

        // better use < rather than <=
        for (int i = 0; i < n; i ++)
        {
              bool flag = true;
              
              for (int j = 0; j < sub.length(); j ++)
              {
                  if (source.at(i + j) != sub.at(j))
                  {
                    flag = false;
                    break;
                  }
              }
              
              if (flag) return i;
        }
        
        return -1;
    }    
};

int main ()
{
    Solution testSolution;
    string s1 = "mississippi";
    string s2 = "issi";
    
    cout << testSolution.substr(s1, s2) << endl;
    
    getchar();
    
    return 0;
}
