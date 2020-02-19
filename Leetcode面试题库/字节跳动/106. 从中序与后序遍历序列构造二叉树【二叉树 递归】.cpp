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
    // 递归实现
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        // 先获取当前根部,值为postorder的最后一个数
        if(postorder.size()==0)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder.back());
        // 然后根据根将inoder分为两个部分
        vector<int>::iterator mid = find(inorder.begin(),inorder.end(),postorder.back());
        vector<int> left_inorder(inorder.begin(),mid);
        vector<int> right_inorder(mid+1,inorder.end());

        // 将postorder分成两部分
        vector<int> left_postorder(postorder.begin(),postorder.begin()+left_inorder.size());
        vector<int> right_postorder(postorder.end()-1-right_inorder.size(),postorder.end()-1);

        // 递归
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder,right_postorder);
        return root;
    }
    void printtree(TreeNode* root)
    {
        if(root == NULL)
        {
            cout<<"NULL ";
            return;
        }
        cout<<root->val<<" ";
        printtree(root->left);
        printtree(root->right);
    }
};

int main()
{
        vector<int> inorder={1,2};
        vector<int> postorder={2,1};
        Solution test;
        test.printtree(test.buildTree(inorder,postorder));

}