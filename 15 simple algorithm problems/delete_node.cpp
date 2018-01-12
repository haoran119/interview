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

    void Test(ListNode* inListNode)
    {
         delete inListNode;
         inListNode = NULL;
         cout << inListNode << endl;

         PrintListNode(inListNode);
    }
    
    void DeleteNode(ListNode* pInHead, ListNode* pToBeDeleted)
    {
         cout << "Entry void DeleteNode(ListNode* pInHead, ListNode* pToBeDeleted)\n" << endl;

         // Check NULL always
         if (pInHead == NULL || pToBeDeleted == NULL)
            return;
         
//         PrintListNode(pInHead);
         
         // Delete non-tail node including head node
         if (pToBeDeleted->next != NULL) {
            ListNode* pNext = pToBeDeleted->next;
            pToBeDeleted->val = pNext->val;
            pToBeDeleted->next = pNext->next;
            
            delete pNext;
            pNext = NULL;
         } else { // Delete tail
            ListNode* pPre = pInHead;
         
            while (pPre->next != pToBeDeleted && pPre != NULL) 
                  pPre = pPre->next;
         
            if (pPre == NULL)
               return;
         
            pPre->next = NULL;
            delete pToBeDeleted;
            pToBeDeleted = NULL;
         }                  
    }
};

int main ()
{
    Solution testSolution;
    int count = 5;
 
    for (int k = 0; k <= count; k ++)
    {
        ListNode* pHead = NULL;
        ListNode* pCur = NULL;
        ListNode* pDel = NULL;
        
        for (int i = 0; i < count; i ++)
        {
            ListNode* pTemp = new ListNode(i);
            
            if (i == 0)
                pHead = pCur = pTemp;
            else {
                pCur->next = pTemp;
                pCur = pCur->next; // pCur->next == pTemp
            }
            
            if (i == k) 
               pDel = pTemp;
        }
           
        cout << "pHead = " << pHead << endl;
        if (pHead != NULL)
           cout << "pHead->val = " << pHead->val << endl;
        cout << "pDel = " << pDel << endl;
        if (pDel != NULL)
           cout << "pDel->val = " << pDel->val << endl;
        cout << ((pHead == pDel) ? "pHead == pDel" : "pHead != pDel") << endl;
        cout << endl;

       // Print Linkedlist
        testSolution.PrintListNode(pHead);        
         
        testSolution.DeleteNode(pHead, pDel);
//        testSolution.Test(pHead);

/*
        delete pDel;
        pDel = NULL;
        pHead = NULL;
*/        
        cout << "pHead = " << pHead << endl;
        if (pHead != NULL)
           cout << "pHead->val = " << pHead->val << endl;
        cout << "pDel = " << pDel << endl;
        if (pDel != NULL)
           cout << "pDel->val = " << pDel->val << endl;
        cout << endl;

        // Print Linkedlist
        testSolution.PrintListNode(pHead);        
    }   
        
    getchar();
    
    return 0;
}
