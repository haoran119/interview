/*
https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. 

A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 

For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        std::vector< std::vector<int> > f(s1.size() + 1, std::vector<int>(s2.size() + 1));

        for (auto i = 0; i <= s1.size(); ++ i) {
            for (auto j = 0; j <= s2.size(); ++ j) {
                if (i == 0 || j == 0) {
                    f.at(i).at(j) = 0;
                }
                else if (s1.at(i - 1) == s2.at(j - 1)) {
                    f.at(i).at(j) = f.at(i - 1).at(j - 1) + 1;
                }
                else {
                    f.at(i).at(j) = std::max(f.at(i - 1).at(j), f.at(i).at(j - 1));
                }
            }
        }
        
        return f.at(s1.size()).at(s2.size());
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
