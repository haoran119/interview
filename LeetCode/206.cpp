//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Iterative solution
    ListNode* reverseList(ListNode* head) {
        // corner case
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *pPre = nullptr, *pCur = head;
        
        while (pCur != nullptr) {
            ListNode* pNext = pCur->next; // store the next pointer
            pCur->next = pPre; // reverse the previous and current pointer
            
            // move the previous and current pointer rightward for the next loop
            pPre = pCur;
            pCur = pNext;
        }
        
        return pPre;
    }
    
    // Recursive solution
    ListNode* reverseList2(ListNode* head) {
        ListNode *pPrevious = nullptr, *pCurrent = head;
        
        return reverse(pPrevious, pCurrent);
    }
    
    ListNode* reverse(ListNode* pPre, ListNode* pCur) {
        if (pCur == nullptr) return pPre;
        
        ListNode* pNext = pCur->next;
        pCur->next = pPre;
        
        return reverse(pCur, pNext);
    }
    
    // Tricky Recursive solution
    ListNode* reverseList3(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* p = reverseList3(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return p;
    }
    
    ListNode* createList() {
        ListNode    *pCur = nullptr, *pHead = nullptr;
        
        for (int i = 0; i < 10; i ++) {
            ListNode* pTemp = new ListNode(i);
            
            if (0 == i) {
                pHead = pCur = pTemp;
            } else {
                pCur->next = pTemp;
                pCur = pCur->next;
            }
        }
        
        return pHead;
    }
    
    void printList(ListNode* head) {
        if (head != nullptr) {
            cout << head->val << endl;
            printList(head->next);
        } else {
            cout << endl;
        }
    }
    
    void deleteList(ListNode** head) {
        ListNode* pDel = *head;
        
        while (pDel != nullptr) {
            ListNode* pNext = pDel->next;
            
            delete pDel;
            pDel = nullptr;
            
            pDel = pNext;
        }

        // neccessary?
        *head = nullptr;
    }
};

int main(int argc, char* argv[])
{
    Solution    testSolution;
    
    /*
     0
     1
     2
     3
     4
     5
     6
     7
     8
     9
     
     9
     8
     7
     6
     5
     4
     3
     2
     1
     0
     */
    // call reverseList()
    ListNode* pHead = testSolution.createList();
    
    testSolution.printList(pHead);
    
    ListNode* pRHead = testSolution.reverseList(pHead);
    
    testSolution.printList(pRHead);

    testSolution.deleteList(&pRHead);

    // call reverseList2()
    pHead = testSolution.createList();
    
    testSolution.printList(pHead);
    
    pRHead = testSolution.reverseList2(pHead);
    
    testSolution.printList(pRHead);
    
    testSolution.deleteList(&pRHead);

    // call reverseList3()
    pHead = testSolution.createList();
    
    testSolution.printList(pHead);
    
    pRHead = testSolution.reverseList3(pHead);
    
    testSolution.printList(pRHead);
    
    testSolution.deleteList(&pRHead);

    return 0;
}
