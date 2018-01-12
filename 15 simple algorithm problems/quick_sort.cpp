#include <iostream>
#include <vector>
using namespace std;
 
class Solution 
{
public:
    // Pass in reference of vector parameter
    void quickSort(vector<int> &a, int inLeft, int inRight)
    {       
        cout << "Entry void qSort(vector<int> array, int left, int right)\n" << endl;
        
        if (inLeft >= inRight) 
           return;
        
        int i = inLeft, j = inRight, temp = a[inLeft];

        while (i < j)
        {
              // Scan from right to left
              while ((i < j) && (a[j] >= temp)) 
                    j --;
              if (i < j) 
                 a[i ++] = a[j];
                 
              // Scan from left to right
              while ((i < j) && (a[i] <= temp)) 
                    i ++;
              if (i < j)
                 a[j --] = a[i];                         
        }
        // Base value temp is on the right position
        a[i] = temp;
        
        // Divide and conquer
        quickSort(a, inLeft, i - 1);
        quickSort(a, i + 1, inRight);        
    }
};

int main ()
{
    Solution testSolution;
    int array[] = {0, 1, 5, 9, 0, 2, 6, 7, 8, 3, 4};
//    int array[] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0};
//    int array[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    vector<int> vecArray(array, array + 11);
    
    for (vector<int>::const_iterator vecCIT = vecArray.begin(); vecCIT != vecArray.end(); vecCIT ++)
        cout << *vecCIT << endl;
    cout << endl;

    testSolution.quickSort(vecArray, 0, vecArray.size() - 1);
        
    for (vector<int>::const_iterator vecCIT = vecArray.begin(); vecCIT != vecArray.end(); vecCIT ++)
        cout << *vecCIT << endl;
    cout << endl;
            
    getchar();
    
    return 0;
}
