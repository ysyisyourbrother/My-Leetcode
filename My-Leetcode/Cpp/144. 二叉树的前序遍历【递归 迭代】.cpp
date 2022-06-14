#include<iostream>
#include<stack>  // 引入标准模板库stack头文件
using namespace std;
 
struct Tree
{
	char data;
	Tree* Lson;
	Tree* Rson;
};

// 非递归前序遍历
void PreOrder_Nor1(Tree* tree)
{
 
	if (tree == NULL)
		return;
	stack<Tree*>s;  //创建一个空栈
	while (tree != NULL || !s.empty())
	{
		while (tree != NULL)
		{
			cout << tree->data << " ";
			s.push(tree);
			tree = tree->Lson;
		}
		if (!s.empty())
		{
			tree = s.top();	
			tree = tree->Rson;
			s.pop();
		}
	}
}

vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt->right);
                v.push_back(rt->val);
                rt=rt->left;
            }
            rt=S.top();S.pop();
        }
        return v;        
    }
