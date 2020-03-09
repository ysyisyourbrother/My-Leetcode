#include "headfile.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        int layer = 0; // 记录当前遍历的层数
        que.push(root);
        while(!que.empty())
        {
            stack<TreeNode*> mysta; // 定义一个栈
            vector<int> sub_res; // 每一层答案的列表
            while(!que.empty())
            {
                TreeNode* cur = que.front();
                mysta.push(cur);
                sub_res.push_back(cur->val);
                que.pop();
            }
            res.push_back(sub_res); // 将每一层的答案加入res中

            // 从stack中取出所有的节点，将子节点加入队列中  
            if(layer%2==0)// 如果当前是偶数层，则下面的要从右向左push
            {
                while(!mysta.empty())
                {
                    TreeNode* cur = mysta.top();
                    mysta.pop();
                    if(cur->right!=NULL)
                        que.push(cur->right);
                    if(cur->left!=NULL)
                        que.push(cur->left);
                }
            }
            else // 奇数层，从左向右push
            {
                while(!mysta.empty())
                {
                    TreeNode* cur = mysta.top();
                    mysta.pop();
                    if(cur->left!=NULL)
                        que.push(cur->left);
                    if(cur->right!=NULL)
                        que.push(cur->right);
                }
            }
            layer++;
        }
        return res;
    }
};