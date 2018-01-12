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
    void PrintList(ListNode *pListNode)
    {
         if (pListNode != NULL) {
            cout << pListNode->val << endl;
            PrintList(pListNode->next);
         } else
            cout << "NULL\n" << endl;
    }
    
    int getLengthOfList(const ListNode *pListNode)
    {
        int length = 0;
        
        while (pListNode != NULL)
        {
              pListNode = pListNode->next;
              length ++;
        }

        return length;              
    }
    
    ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) 
    {
//              cout << "Entry ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)" << endl;
              
              int len1 = getLengthOfList(pHead1);
              int len2 = getLengthOfList(pHead2);
              
              if (len1 > len2)
              {
                    int gap = len1 - len2;
                    for (int i = 0; i < gap; i ++)
                        pHead1 = pHead1->next;                       
              } 
              else 
              {
                    int gap = len2 - len1;
                    for (int i = 0; i < gap; i ++)
                       pHead2 = pHead2->next;                                          
              }
              
              while ((pHead1 != NULL) && (pHead2 != NULL) && (pHead1 != pHead2))
              {
                    pHead1 = pHead1->next;
                    pHead2 = pHead2->next;
              }

              return pHead1;
    }
};

int main ()
{
    Solution testSolution;
    int count = 10, k = 0;
    
    ListNode *pMHead = NULL;
    ListNode *pMCur = NULL;
    ListNode *pKNode = NULL;
    
    for (int i = 0; i < count; i ++)
    {
        ListNode *pTemp = new ListNode(i);
        
        if (i == 0)
            pMHead = pMCur = pTemp;
        else {
            pMCur->next = pTemp;
            pMCur = pMCur->next; // pMCur->next == pTemp
        }
        
        if (i == k)
           pKNode = pMCur;
    }
    
    // Print Head       
    cout << "pMHead = " << pMHead << endl;
    if (pMHead != NULL)
       cout << "pMHead->val = " << pMHead->val << endl;
    cout << endl;
    
    // Print Kth Node       
    cout << "pKNode = " << pKNode << endl;
    if (pKNode != NULL)
       cout << "pKNode->val = " << pKNode->val << endl;
    cout << endl;

    // Print Linkedlist
    cout << "PrintList(pMHead)" << endl;
    testSolution.PrintList(pMHead);        
    
    ListNode *pTarget = testSolution.FindFirstCommonNode(pMHead, pKNode);
    
    // Print Head       
    cout << "pMHead = " << pMHead << endl;
    if (pMHead != NULL)
       cout << "pMHead->val = " << pMHead->val << endl;
    cout << endl;
    
    // Print Kth Node       
    cout << "pTarget = " << pTarget << endl;
    if (pTarget != NULL)
       cout << "pTarget->val = " << pTarget->val << endl;
    cout << endl;

    // Print Linkedlist
    cout << "PrintList(pMHead)" << endl;
    testSolution.PrintList(pMHead);        

    getchar();
    
    return 0;
}
