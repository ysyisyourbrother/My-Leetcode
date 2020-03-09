#include "headfile.h"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL || A == NULL) return false;

        // 如果A当前值和B的相同，搜索判断二者是否一样
        if(A->val == B->val)
        {
            if(compare(A,B))
                return true;
        }
        bool left = isSubStructure(A->left,B);
        bool right = isSubStructure(A->right,B);
        return left||right;
    }
    bool compare(TreeNode* A, TreeNode* B) // B只探索不为NULL的那边
    {
        if(A==NULL)
            return false;
        if(A->val != B->val)
            return false;
        bool left=true;
        bool right=true;
        if(B->left != NULL)
            left = compare(A->left,B->left);
        if(B->right != NULL)
            right = compare(A->right,B->right);
        return left && right;
    }
};