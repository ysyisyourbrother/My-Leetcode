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
    TreeNode* mirrorTree(TreeNode* root) {
		if(root==NULL) return NULL;
		TreeNode* node = new TreeNode(root->val); // 构建新的节点
		node->left = mirrorTree(root->right);
		node->right = mirrorTree(root->left);
		return node;
    }
};