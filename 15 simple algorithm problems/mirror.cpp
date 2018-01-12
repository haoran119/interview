#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
 
class Solution 
{
public:
    TreeNode* CreateTree(const vector<int> &vec, const int &pos)
    {
//              cout << "Entry TreeNode* CreateTree(const vector<int> &vec, const int &pos)\n" << endl;
              
//              cout << "pos = " << pos << endl;
//              cout << "vec.size() = " << vec.size() << endl;
            
              // Pay attention to >=, or else infinite loop    
              if (pos >= vec.size()) return NULL;
              
//              cout << "vec[pos] = " << vec[pos] << endl;

              TreeNode *pCur = new TreeNode(vec[pos]);
//              cout << "pCur->val = " << pCur->val<< endl;
              pCur->left = CreateTree(vec, 2 * pos);
              pCur->right = CreateTree(vec, 2 * pos + 1);              
              
              return pCur;
    }
    
    void PrintTree(TreeNode *pTreeNode)
    {
         if (pTreeNode != NULL) {
            cout << pTreeNode->val << endl;
            PrintTree(pTreeNode->left);
            PrintTree(pTreeNode->right);
         } 
    }
    
    void Mirror(TreeNode *pRoot) 
    {
//         cout << "Entry void Mirror(TreeNode *pRoot) " << endl;
         
         // Corner case
         if ((pRoot == NULL) || ((pRoot->left == NULL) && (pRoot->right == NULL))) return;
         
         // swap two ptr rathet than value
         swap(pRoot->left, pRoot->right);
         
         Mirror(pRoot->left);
         Mirror(pRoot->right);                  
    }
};

int main ()
{
    Solution testSolution;
    int count = 8;
    int array[] = {0, 8, 6, 10, 5, 7, 9, 11};
    vector<int> vecArray(array, array + count);

    TreeNode *pMRoot = testSolution.CreateTree(vecArray, 1);
/*
    cout << root << endl;
    cout << root->val << endl;
*/    
    testSolution.PrintTree(pMRoot);
    cout << endl;

    testSolution.Mirror(pMRoot);

    testSolution.PrintTree(pMRoot);
    cout << endl;
    
    getchar();
    
    return 0;
}
