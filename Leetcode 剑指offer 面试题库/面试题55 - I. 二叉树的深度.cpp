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
    int maxDepth(TreeNode* root) {
		int max_h = 0;
		dfs(root, max_h);
		return max_h;	
    }
	int dfs(TreeNode* root, int& max_h)
	{
		if(root == NULL)
			return 0;
		return max(dfs(root->left, max_h),dfs(root->right,max_h))+1;		
	}
};