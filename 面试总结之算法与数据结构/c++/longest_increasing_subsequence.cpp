/*
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the 
subsequence are sorted in increasing order. 

For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}. 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       if (n == 1) {
           return 1;
       }
       
       std::vector<int> v_LIS;
       
       for (auto i = 0; i < n; ++ i) {
           // find the first index "left" where LIS[left] >= num
           int left = 0, right = v_LIS.size() - 1;
           
           while (left <= right) {
               auto mid = left + (right - left) / 2;
               if (v_LIS.at(mid) >= a[i]) {
                   right = mid - 1;
               }
               else {
                   left = mid + 1;
               }
           }
           
           // if num is greater than all LIS elements, append it
           if (left == v_LIS.size()) {
               v_LIS.emplace_back(a[i]);
           }
           // if LIS[left-1] < num <= LIS[left], LIS[left] = num
           else {
               v_LIS.at(left) = a[i];
           }
       }

       return v_LIS.size();
    }

    int longestSubsequence1(int n, int a[])
    {
       // your code here
       if (n == 1) {
           return 1;
       }
       
       std::vector<int> v_LIS;
       
       for (auto i = 0; i < n; ++ i) {
           // find the first index "left" where LIS[left] >= num
           auto it = std::lower_bound(v_LIS.begin(), v_LIS.end(), a[i]);
           
           // if num is greater than all LIS elements, append it
           if (it == v_LIS.end()) {
               v_LIS.emplace_back(a[i]);
           }
           // if LIS[left-1] < num <= LIS[left], LIS[left] = num
           else {
               *it = a[i];
           }
       }

       return v_LIS.size();
    }

    int longestSubsequence2(int n, int a[])
    {
       // your code here
       if (n == 1) {
           return 1;
       }
       
       std::vector<int> f(n, 1);

       for (auto i = 0; i < n; ++ i) {
           for (auto j = 0; j < i; ++ j) {
               if (a[i] > a[j] && f.at(i) < f.at(j) + 1) {
                   f.at(i) = f.at(j) + 1;
               }
           }
       }
       
       return *std::max_element(f.begin(), f.end());
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
