#include <iostream>
using namespace std;

struct ListNode 
{
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
    void PrintListNodeReversely(ListNode* inListNode)
    {
         if (inListNode != NULL)
         {
            PrintListNodeReversely(inListNode->next);
            cout << inListNode->val << endl;
         }         
    }
};

int main ()
{
    Solution testSolution;
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    
    for (int i = 1; i < 10; i ++)
    {
        ListNode* tmpLN = new ListNode(i);
        cur->next = tmpLN;
        cur = cur->next; // cur->next == tmpLN        
    }

    // Print head node        
    testSolution.PrintListNodeReversely(head);
        
    getchar();
    
    return 0;
}
