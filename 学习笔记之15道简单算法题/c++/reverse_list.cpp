#include <iostream>
using namespace std;

struct ListNode 
{
       int val;
       ListNode *next;
       ListNode(int x = 0) : val(x), next(NULL) {}
};
 
class Solution 
{
public:
    void PrintList(ListNode *inListNode)
    {
         if (inListNode != NULL) {
            cout << inListNode->val << endl;
            PrintList(inListNode->next);
         } else
            cout << "NULL\n" << endl;
    }
    
    // Assign in ptr of the head ptr
    void DeleteList(ListNode **pInHead)
    {
         cout << "Entry void DeleteList(ListNode **pInHead)\n" << endl;
         
         ListNode *pDel = *pInHead;
         
         while (pDel != NULL)
         {
               // Reserve the address of the next node
               ListNode *pNext = pDel->next;              
               // Delete the current node
               delete pDel;
               pDel = NULL;
               // Move to the next node
               pDel = pNext;
         }

         // Set head to NULL         
         *pInHead = NULL;
    }
    
    ListNode* ReverseList(ListNode* pHead)
    {
         cout << "Entry ListNode* ReverseList(ListNode* pHead)\n" << endl;

         // Corner case
         if (pHead == NULL)       return NULL;
         
         ListNode *pPre = NULL, *pRHead = NULL, *pCur = pHead;
         
         while (pCur != NULL)
         {
               // Reserve the next node
               ListNode *pNext = pCur->next;               
               // Reserve the address of the last node of original list
               if (pNext == NULL) pRHead = pCur;
               // Insert current node
               pCur->next = pPre;
               // Move the previous ptr
               pPre = pCur;
               // Assign the next node back
               pCur = pNext;
         }
         
         return pRHead;
    }
};

int main ()
{
    Solution testSolution;
    int count = 10;
    
    ListNode *pMHead = NULL;
    ListNode *pMCur = NULL;
    
    for (int i = 0; i < count; i ++)
    {
        ListNode *pTemp = new ListNode(i);
        
        if (i == 0)
            pMHead = pMCur = pTemp;
        else {
            pMCur->next = pTemp;
            pMCur = pMCur->next; // pCur->next == pTemp
        }
    }
    
    // Print Head       
    cout << "pMHead = " << pMHead << endl;
    if (pMHead != NULL)
       cout << "pMHead->val = " << pMHead->val << endl;
    cout << endl;
    
    // Print Linkedlist
    cout << "PrintList(pMHead)" << endl;
    testSolution.PrintList(pMHead);        

    cout << "Test ReverseList(pMHead)\n" << endl;     
    ListNode *pMRHead = testSolution.ReverseList(pMHead);
    
    // Print Reversed Head       
    cout << "pMRHead = " << pMRHead << endl;
    if (pMRHead != NULL)
       cout << "pMRHead->val = " << pMRHead->val << endl;
    cout << endl;
    
    // Print Linkedlist
    cout << "PrintList(pMRHead)" << endl;
    testSolution.PrintList(pMRHead);        

    // Print Head       
    cout << "pMHead = " << pMHead << endl;
    if (pMHead != NULL)
       cout << "pMHead->val = " << pMHead->val << endl;
    cout << endl;
    
    // Print Linkedlist
    cout << "PrintList(pMHead)" << endl;
    testSolution.PrintList(pMHead);        

    cout << "DeleteList(&pMRHead)" << endl;
    testSolution.DeleteList(&pMRHead);
    
    // Print Reversed Head       
    cout << "pMRHead = " << pMRHead << endl;
    if (pMRHead != NULL)
       cout << "pMRHead->val = " << pMRHead->val << endl;
    cout << endl;
    
    // Print Linkedlist
    cout << "PrintList(pMRHead)" << endl;
    testSolution.PrintList(pMRHead);        

    // Print Head       
    cout << "pMHead = " << pMHead << endl; // It is not NULL, the space is free'ed?
    if (pMHead != NULL)
       cout << "pMHead->val = " << pMHead->val << endl;
    cout << endl;
    
    // Print Linkedlist
//    cout << "PrintList(pMHead)" << endl;
//    testSolution.PrintList(pMHead);        

    getchar();
    
    return 0;
}
