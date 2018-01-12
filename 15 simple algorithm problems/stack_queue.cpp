#include <iostream>
#include <stack>
using namespace std;
 
class Solution 
{
public:
       void push(int node) 
       {
            stack1.push(node);
       }
       
       int pop() 
       {
            int result = 0;
            
            if (stack2.empty())
            {
                while (!stack1.empty())
                {
                      stack2.push(stack1.top());
                      stack1.pop();
                }                  
            }    
            
            result = stack2.top();
            stack2.pop();
            
            return result;
       }
       
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main ()
{
    Solution testSolution;
    int count = 10;

    // Case 1    
    cout << "CASE 1\n" << endl;
    
    for (int i = 0; i < count; i ++)
    {
        testSolution.push(i);
    }
    
    for (int i = 0; i < count; i ++)
    {
        cout << testSolution.pop() << endl;    
    }

    // Case 2
    cout << "\nCASE 2\n" << endl;

    for (int i = 0; i < count; i ++)
    {
        testSolution.push(i);
        cout << testSolution.pop() << endl;    
    }

    // Case 3
    cout << "\nCASE 3\n" << endl;

    for (int i = 0; i < count / 2; i ++)
    {
        testSolution.push(i);
    }
    
    cout << testSolution.pop() << "\n" << endl;    

    for (int i = count / 2; i < count; i ++)
    {
        testSolution.push(i);
    }
    
    for (int i = 0; i < count - 1; i ++)
    {
        cout << testSolution.pop() << endl;        
    }

    getchar();
    
    return 0;
}
