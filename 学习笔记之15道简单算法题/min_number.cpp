#include <iostream>
#include <vector>
#include <cstdio> // sprintf
#include <algorithm>  // sort
using namespace std;
 
class Solution 
{
public:
    // Need to define static
    static bool compare(const string &sA, const string &sB)
    {
           string sAB = sA + sB;
           string sBA = sB + sA;

         return sAB < sBA;
    }
       
    string PrintMinNumber(vector<int> numbers)
    {       
        cout << "Entry string PrintMinNumber(vector<int> numbers)\n" << endl;

        string result = "";

        // Corner case
        if (numbers.size() == 0) return result;
        
        vector<string> sNumbers;
        char *sTemp = new char[10]; // Remember to initialize ptr
        
        for (vector<int>::const_iterator vecCIT = numbers.begin(); vecCIT != numbers.end(); vecCIT ++)
        {
//         string sTemp = to_string(*vecCIT); // C++11
            sprintf(sTemp, "%d", *vecCIT);
            sNumbers.push_back(sTemp);
        }

        // Use self-defined compare function
        sort(sNumbers.begin(), sNumbers.end(), compare);

        for (vector<string>::const_iterator vecCIT = sNumbers.begin(); vecCIT != sNumbers.end(); vecCIT ++)
            result += *vecCIT;

        return result;
    }
};

int main ()
{
    Solution testSolution;
    int array[] = {3, 32, 321};
    vector<int> vecArray(array, array + 3);
//    vector<int> vecArray;
        
    for (vector<int>::const_iterator vecCIT = vecArray.begin(); vecCIT != vecArray.end(); vecCIT ++)
        cout << *vecCIT << endl;
    cout << endl;

    cout << testSolution.PrintMinNumber(vecArray) << endl;
                
    getchar();
    
    return 0;
}
