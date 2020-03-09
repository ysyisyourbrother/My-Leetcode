class Solution {
public:
    int res;
    Solution():res(0){}
    
    int kthLargest(TreeNode* root, int k) {
        helper(root,k);
        return res;
    }
    void helper(TreeNode * root, int & k)
    {
        if(k<=0)
            return;
        
        if(root->right !=NULL) helper(root->right,k);
        if((--k)==0) // 如果刚好是第k个，直接保存结果
        {
            cout<<root->val;
            res = root->val;
            return;
        }
        if(root->left!=NULL) helper(root->left,k);
    }
};