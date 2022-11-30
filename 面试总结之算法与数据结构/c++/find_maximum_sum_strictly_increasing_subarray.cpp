/*
https://www.geeksforgeeks.org/find-maximum-sum-strictly-increasing-subarray/
https://practice.geeksforgeeks.org/problems/find-maximum-sum-strictly-increasing-subarray4443/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Given an array of positive integers. Find the maximum sum of strictly increasing subarrays. 

Note that this problem is different from maximum subarray sum and maximum sum increasing subsequence problems.

Examples: 

Input  : arr[] = {1, 2, 3, 2, 5, 1, 7}
Output : 8
Explanation :  Some Strictly increasing subarrays are 
{1, 2, 3} sum = 6, 
{2, 5} sum = 7, 
{1, 7} sum 8 
Maximum Sum = 8 

Input : arr[] = {1, 2, 2, 4}
Output: 6
Explanation : Increasing subarray with maximum sum is 6.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
public:
    int maxsum_SIS(int arr[] , int n)
    {
        // Your code goes here   
        if (n == 1) {
            return arr[0];
        }
        
        auto result{arr[0]}, sum{arr[0]};

        for (auto i = 1; i < n; ++ i) {
            if (arr[i] > arr[i - 1]) {
                sum += arr[i];
                result = max(result, sum);
            }
            else {
                result = max(result, sum);
                sum = arr[i];
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.maxsum_SIS(a, n)<<endl;
    }
}

// } Driver Code Ends
