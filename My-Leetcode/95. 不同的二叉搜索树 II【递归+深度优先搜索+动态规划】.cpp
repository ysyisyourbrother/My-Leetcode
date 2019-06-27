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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>{};
        return recursion(1,n);
    }
    vector<TreeNode*> recursion(int begin, int end) // 递归函数,递归建造从start到end的所有可能二叉树并用vector收集起来
    {
        vector<TreeNode*> res;// 返回start 到end每个树的根指针
        if (begin > end)// 结束递归条件
        {
            res.push_back(NULL);
            return res;
        }
        for (int i = begin; i <= end; ++i)
        {
            vector<TreeNode*> left_trees = recursion(begin, i-1);//递归建立左边的树
            vector<TreeNode*> right_trees = recursion(i+1, end);//递归右边的树
            for (auto l : left_trees)
            {
                for (auto r : right_trees)
                {
                    //重复用了建造好的树指针，也可以算是一个动态规划
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }

        }
        return res;
    }
};