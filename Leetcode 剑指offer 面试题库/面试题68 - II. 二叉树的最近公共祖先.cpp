#include "headfile.h"
using namespace std;
class Solution {
public:
    TreeNode * res;
    Solution():res(NULL){}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 深度优先搜索搜索
        helper(root,p,q);
        return res;
    }
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return false;
        if(root == p || root == q) 
        {
            if(helper(root->left,p,q) || helper(root->right,p,q))
                res = root;
            return true;
        }
        bool left = helper(root->left,p,q);
        bool right = helper(root->right,p,q);
        if(left && right)
        {
            res = root;
            return true;
        }
        else if(left || right)
            return true;
        return false;
    }   
};