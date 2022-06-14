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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        queue<TreeNode*> myqu;
        vector<int> subres; // 保存每一层的答案
        myqu.push(root);
        subres.push_back(root->val);
        while(!myqu.empty())
        {   
            int s = subres.size(); // 获取每一层有多少个元素
            res.push_back(subres);
            vector<int>().swap(subres);// 清空
            for(int i =0;i<s;i++)
            {
                TreeNode* cur = myqu.front();
                if(cur->left != NULL)
                {
                    myqu.push(cur->left);
                    subres.push_back(cur->left->val);
                }
                    
                if(cur->right != NULL)
                {
                    myqu.push(cur->right);
                    subres.push_back(cur->right->val);
                }
                myqu.pop();
            }
        }
        return res;
    }
};