/*
https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
https://www.geeksforgeeks.org/longest-common-substring-dp-29/

Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 

Examples : 

Input : X = “GeeksforGeeks”, y = “GeeksQuiz” 
Output : 5 
Explanation:
The longest common substring is “Geeks” and is of length 5.

Input : X = “abcdxyz”, y = “xyzabcd” 
Output : 4 
Explanation:
The longest common substring is “abcd” and is of length 4.

Input : X = “zxabcdezy”, y = “yzabcdezx” 
Output : 6 
Explanation:
The longest common substring is “abcdez” and is of length 6.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        std::vector< std::vector<int> > f(S1.size() + 1, std::vector<int>(S2.size() + 1));
        auto result{0};
        
        for (auto i = 0; i <= S1.size(); ++ i) {
            for (auto j = 0; j <= S2.size(); ++ j) {
                if (i == 0 || j == 0) {
                    f.at(i).at(j) = 0;
                }
                else if (S1.at(i - 1) == S2.at(j - 1)) {
                    f.at(i).at(j) = f.at(i - 1).at(j - 1) + 1;
                    result = std::max(result, f.at(i).at(j));
                }
                else {
                    f.at(i).at(j) = 0;
                }
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
