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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int lenth=preorder.size();
        if(lenth<=0) return NULL;
        int startPre=0,endPre=lenth-1,startIn=0,endIn=lenth-1;
        return constructTree(startPre,endPre,startIn,endIn,preorder, inorder);
    }

    TreeNode* constructTree(int startPre,int endPre,int startIn,int endIn,vector<int>& preorder, vector<int>& inorder)
    {
        if(startPre>endPre)
            return NULL;
        TreeNode* root=new TreeNode(preorder[startPre]);
        int leftTree=0;
        while(inorder[startIn+leftTree]!=preorder[startPre])
        {
            leftTree++;
        }
        // 中序中根的左边是左子树的结点，有多少个，对应的前序接下来多少个结点是在左子树
        root->left=constructTree(startPre+1,startPre+leftTree,startIn,startIn+leftTree-1,preorder, inorder);
        root->right=constructTree(startPre+leftTree+1,endPre,startIn+leftTree+1,endIn,preorder, inorder);
        return root;
    }
};