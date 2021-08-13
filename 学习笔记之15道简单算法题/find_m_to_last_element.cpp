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
    void PrintListNode(ListNode* inListNode)
    {
         if (inListNode != NULL) {
            cout << inListNode->val << endl;
            PrintListNode(inListNode->next);
         } else
            cout << endl;
    }
    
    ListNode *findMToLastElement(ListNode* pInHead, int m)
    {
         cout << "Entry ListNode *findMToLastElement(ListNode* pInHead, int m)\n" << endl;
         
         ListNode *pCur = NULL, *pMPre = NULL;
         
         // Corner case
         if (pInHead == NULL) return NULL;
         
         pCur = pMPre = pInHead;

         // Move pCur forward m elements
         for (int i = 0; i < m; i ++)
         {
             if (pCur->next != NULL)
                pCur = pCur->next;
             else
                return NULL;
         }

         // Move forward together until pCur reach the tail
         while (pCur->next != NULL)
         {
               pCur = pCur->next;
               pMPre = pMPre->next;               
         }
         
         // Now pMPre points to the M to last element
         return pMPre;
    }
};

int main ()
{
    Solution testSolution;
    int count = 10;
    
    ListNode *pHead = NULL;
    ListNode *pCur = NULL;
    
    for (int i = 0; i < count; i ++)
    {
        ListNode *pTemp = new ListNode(i);
        
        if (i == 0)
            pHead = pCur = pTemp;
        else {
            pCur->next = pTemp;
            pCur = pCur->next; // pCur->next == pTemp
        }
    }
    
    // Print Head       
    cout << "pHead = " << pHead << endl;
    if (pHead != NULL)
       cout << "pHead->val = " << pHead->val << endl;
    cout << endl;
    
    // Print Linkedlist
    cout << "PrintListNode(pHead)" << endl;
    testSolution.PrintListNode(pHead);        

    cout << "Test findMToLastElement(pHead, 0)\n" << endl;     
    ListNode *pMToLastElement = testSolution.findMToLastElement(pHead, 0);
    
    // Print Head       
    cout << "pHead = " << pHead << endl;
    if (pHead != NULL)
       cout << "pHead->val = " << pHead->val << endl;
    cout << endl;
    
    // Print M to last element
    cout << "pMToLastElement = " << pMToLastElement << endl;
    if (pMToLastElement != NULL)
       cout << "pMToLastElement->val = " << pMToLastElement->val << endl;
    cout << endl;
    
    getchar();
    
    return 0;
}
