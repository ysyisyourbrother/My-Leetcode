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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root->left,root->right);
    }
    bool helper(TreeNode* one, TreeNode* two)
    {
        if(one == NULL && two == NULL) return true;
        if(one != NULL && two==NULL || one==NULL && two != NULL) return false; // 有一者为null另一者不为返回false

        // 当两者都不为NULL是递归判断
        return (one->val == two->val) && helper(one->left,two->right) && helper(one->right,two->left);
    }
};