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
	bool flag = true;
    bool isBalanced(TreeNode* root) {
		helper(root);
		return flag;
    }
	int helper(TreeNode* root)// 递归，返回左右子树比较深的一者的高度，一旦出现flag已经为flase直接返回
	{	
		if(!flag) return -1; // 直接返回任意数
		if(root == NULL) return 0; // 为空的时候返回0
		int left_h = helper(root->left);
		int right_h = helper(root->right);
		if(abs(left_h-right_h)<2) return max(left_h,right_h)+1; // 返回子树高度
		else
			flag = false,return -1;
	}
};