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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
		int m = min(p->val,q->val);
		int n = max(p->val,q->val); // 获取两个节点的值 标记为最大和最小方便比较
		TreeNode* cur = root;
		while(cur!=NULL)
		{
			if(cur->val >m && cur->val<n) // 说明mn分别在左右子树，说面他就是公共祖先
				break;
			if(cur->val == m || cur->val == n) // 如果有一个目标就是当前节点，说明他就是公共祖先
				break;
			if(cur->val<m)
				cur = cur->right;
			else if(cur->val>n)
				cur = cur->left;
		}
		return cur;
    }
};