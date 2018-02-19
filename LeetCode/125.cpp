#include <iostream>
#include <string>
#include <cctype>  // toupper, isalnum
#include <algorithm>  // transform
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) 
    {
         string sTemp = "", sReverse = "";

         // Convert characters to UPPER
         transform(s.begin(), s.end(), s.begin(), ::toupper);

         // considering only alphanumeric characters
         for (int i = 0; i < s.length(); i ++)
             if (isalnum(s.at(i)))
                sTemp.push_back(s.at(i)); // Appends character to the end of the string, increasing its length by one.

         // Need to allocate space if use reverse_copy
         sReverse.resize(sTemp.length());
         reverse_copy(sTemp.begin(), sTemp.end(), sReverse.begin());
/*
         sReverse = sTemp;
         reverse(sReverse.begin(), sReverse.end());
*/         
/*
         cout << sTemp << endl;
         cout << sReverse << endl;
*/         
         return sTemp == sReverse;
    }
    
    bool isPalindrome2(string s) 
    {
         int start = 0, end = s.length() - 1;

         while (start < end)
         {
               if ( !isalnum(s.at(start)) ) 
                  start ++;
               else if ( !isalnum(s.at(end)) ) 
                    end --;
               else if (toupper(s.at(start)) != toupper(s.at(end))) // Remember toupper 
                      return false;
               else
               {
                   // Remember to move ptr
                   start ++;
                   end --;
               }
         }
         
         return true;
    }
    
};

int main ()
{
    Solution testSolution;
    string sTest[] = {"A man, a plan, a canal: Panama", "race a car"};
    
    for (int i = 0; i < 2; i ++)
        cout << testSolution.isPalindrome(sTest[i]) << endl;
    
    getchar();
    
    return 0;
}
