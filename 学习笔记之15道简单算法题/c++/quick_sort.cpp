#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Pass in reference of vector parameter
    void quickSort(vector<int> &a, int inLeft, int inRight)
    {
        if (inLeft >= inRight)
            return;

        auto i = inLeft, j = inRight, temp = a.at(inLeft);

        while (i < j) {
            // Scan from right to left
            while (i < j and a.at(j) >= temp) {
                -- j;
            }
            if (i < j) {
                a.at(i ++) = a.at(j);
            }

            // Scan from left to right
            while (i < j and a.at(i) <= temp) {
                ++ i;
            }
            if (i < j) {
                a.at(j --) = a.at(i);
            }
        }

        // Base value temp is on the correct position now
        a.at(i) = temp;

        // Divide and conquer
        quickSort(a, inLeft, i - 1);
        quickSort(a, i + 1, inRight);
    }
};

int main ()
{
    auto testSolution = Solution();
    int array[] = {0, 1, 5, 9, 0, 2, 6, 7, 8, 3, 4};
//    int array[] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0};
//    int array[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    vector<int> vecArray(array, array + 11);

    for (auto i : vecArray)
        cout << i << " ";
    cout << endl;

    testSolution.quickSort(vecArray, 0, vecArray.size() - 1);

    for (auto i : vecArray)
        cout << i << " ";
    cout << endl;

    return 0;
}
