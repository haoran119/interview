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
    ListNode* MergeList(ListNode* aListNode, ListNode* bListNode)
    {
         // NULL case
         if (aListNode == NULL)
            return bListNode;
         if (bListNode == NULL)
            return aListNode;

         ListNode* resHead = NULL;         

         if (aListNode->val < bListNode->val) {
            resHead = aListNode;
            aListNode = aListNode->next;
         } else {
            resHead = bListNode;
            bListNode = bListNode->next;
         }
         
         // Reserve the head point         
         ListNode* tmpHead = resHead;

//         PrintListNode(tmpHead);
         
         // Merge two LinkList
         // Remember to check if the current node is NULL
         // assign ListNode to next resHead->next
         // move resHead to the next ptr
         while (aListNode != NULL && bListNode != NULL)
         {
               if (aListNode->val < bListNode->val) {
                  resHead->next = aListNode;
                  aListNode = aListNode->next;
               } else {
                  resHead->next= bListNode;
                  bListNode = bListNode->next;
               }
               resHead = resHead->next;
         }

//         PrintListNode(tmpHead);

         if (aListNode != NULL)
            resHead->next= aListNode;
            
         if (bListNode != NULL)
            resHead->next= bListNode;
         
//         PrintListNode(tmpHead);

         return tmpHead;
    }
    
    void PrintListNode(ListNode* inListNode)
    {
         ListNode* tmpLN = inListNode;
         
         while (tmpLN != NULL)
         {
               cout << tmpLN->val << endl;
               tmpLN = tmpLN->next;
         }         
         cout << endl;
    }
};

int main ()
{
    Solution testSolution;
    ListNode* aHead = new ListNode(1);
    ListNode* cur = aHead;
    
    for (int i = 2; i < 10; i += 2)
    {
        ListNode* tmpLN = new ListNode(i);
        cur->next = tmpLN;
        cur = tmpLN;        
    }
    
//    testSolution.PrintListNode(aHead);
    
    ListNode* bHead = new ListNode(1);
    cur = bHead;
    
    for (int i = 3; i < 10; i += 2)
    {
        ListNode* tmpLN = new ListNode(i);
        cur->next = tmpLN;
        cur = tmpLN;
    }
      
//    testSolution.PrintListNode(bHead);

    ListNode* head = testSolution.MergeList(aHead, bHead);

//    testSolution.PrintListNode(head);

    while (head != NULL)
    {
          cout << head->val << endl;
          head = head->next;
    }
        
    getchar();
    
    return 0;
}
