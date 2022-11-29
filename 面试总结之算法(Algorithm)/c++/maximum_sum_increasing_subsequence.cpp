/*
https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the 
subsequence are sorted in increasing order. 

For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), 
if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    std::vector<int> f(n);  // remember to specify size
	    auto result {0};

	    for (auto i = 0; i < n; ++ i) {
	        f.at(i) = arr[i];
	    }

	    for (auto i = 0; i < n; ++ i) {
	        for (auto j = 0; j < i; ++ j) {
	            if (arr[i] > arr[j] && f.at(i) < f.at(j) + arr[i]) {
	                f.at(i) = f.at(j) + arr[i];
	            }
	        }
	    }
	    
	    for (const auto i : f) {
	        result = max(result, i);
	    }
	    
	    return result;
	}  
};

//{ Driver Code Starts.
int main() 
{   	
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
