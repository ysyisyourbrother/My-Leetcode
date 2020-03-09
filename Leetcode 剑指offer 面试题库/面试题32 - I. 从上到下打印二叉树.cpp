#include "headfile.h"
using namespace std;

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            res.push_back(cur->val);
            que.pop();
            if(cur->left!=NULL) que.push(cur->left);
            if(cur->right !=NULL) que.push(cur->right);
        }
        return res;
    }
};