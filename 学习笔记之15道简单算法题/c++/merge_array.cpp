#include <iostream>
using namespace std;

class Solution 
{
public:
    void MergeArray(int a[],int alen,int b[],int blen)
    {
         int len = alen + blen - 1;
         alen --;
         blen --;
         
         // 用归并排序的思想把两个数组合并 
         while (alen >= 0 && blen >= 0)
         {
               if (a[alen] > b[blen])
                  a[len --] = a[alen --];
               else
                  a[len --] = b[blen --];
         }
         
         while (blen >= 0)
               a[len --] = b[blen --];
    }
};

int main ()
{
    Solution testSolution;
    int arrA[] = {1, 2, 4, 6, 8, 0, 0, 0, 0, 0};
    int arrB[] = {1, 3, 5, 7, 9};
      
    testSolution.MergeArray(arrA, 5, arrB, 5);
    
    for (int i = 0; i < 10; i ++)
        cout << arrA[i] << endl;
        
    getchar();
    
    return 0;
}
