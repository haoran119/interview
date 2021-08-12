#include <iostream>
using namespace std;

class Solution {
public:
/*
    bool isVowels(char chIn)
    {
        return ((toupper(chIn) == 'A' || toupper(chIn) == 'E' || toupper(chIn) == 'I' || toupper(chIn) == 'O' || toupper(chIn) == 'U'));
    }
*/
    
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        string sVowels = "aeiouAEIOU";

        // Remember special case
        if (s == "" || s.length() == 0) return s;
        
        while (i < j)
        {
//            while (!isVowels(s[i]) && (i < j)) i ++;
              while ((sVowels.find(s[i]) == string::npos) && (i < j)) i ++;
//            while (!isVowels(s[j]) && (i < j)) j --;
              while ((sVowels.find(s[j]) == string::npos) && (i < j)) j --;  
                        
            if (i < j)
                swap(s[i], s[j]);
            
            i ++;
            j --;
        }

        return s;
    }
};

int main ()
{
    Solution testSolution;
    string result;
    
    result = testSolution.reverseVowels("hello");    
    cout << result << endl;
    
    char ch;
    cin >> ch;
    
    return 0;
}
