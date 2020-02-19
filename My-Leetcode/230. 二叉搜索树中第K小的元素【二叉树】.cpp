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
    int recursion(TreeNode* root, int& k)
    {
        if(root == NULL)
        {
            return 0;
        }
        int res = recursion(root->left,k); //因为是二叉搜索树，用前序遍历的方法实现
        if(k==0)
        {
            return res;
        }
        k-=1; // 遍历当前根节点
        if(k==0)
        {
            return root->val;
        }
        res = recursion(root->right,k);
        if(k==0)
        {
            return res;
        }
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        return recursion(root, k);
    }
};