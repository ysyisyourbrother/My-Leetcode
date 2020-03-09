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
    vector<vector<int> > res;
    Solution(){}

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> cur;
        helper(root,sum,cur,0);
        return res;   
    }
    void helper(TreeNode* root,int sum, vector<int> cur, int cur_sum)
    {
        // 深度优先搜索
        // 如果到叶子节点时cur_sum等于target 则成功
        if(root ==  NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            if(cur_sum+root->val == sum)
            {
                cur.push_back(root->val);
                res.push_back(cur);
            }
            return;
        }
        cur.push_back(root->val); // 将当前节点加入cur
        helper(root->left, sum, cur, cur_sum+root->val);
        helper(root->right, sum, cur, cur_sum+root->val);
    }

};
