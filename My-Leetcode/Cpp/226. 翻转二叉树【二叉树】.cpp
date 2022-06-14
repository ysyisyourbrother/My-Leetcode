# include "headfile.h"
using namespace std; 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        TreeNode* res = new TreeNode(root->val);
        res->left = invertTree(root->right);
        res->right = invertTree(root->left);
        return res;
    }
};