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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> subres;
            int s = que.size(); // 每一层的大小 
            for(int i =0;i<s;i++) // 遍历一层的所有节点
            {
                TreeNode* cur = que.front();
                subres.push_back(cur->val); // 加入答案中
                que.pop();
                if(cur->left!=NULL) que.push(cur->left);
                if(cur->right!=NULL) que.push(cur->right);
            }
            res.push_back(subres);
        }
        return res;
    }
};