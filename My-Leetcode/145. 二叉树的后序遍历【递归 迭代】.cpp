#include<iostream>
#include<stack>  // 引入标准模板库stack头文件
using namespace std;
 
struct Tree
{
	char data;
	Tree* Lson;
	Tree* Rson;
};

//非递归后序遍历
void PosOrder(Tree* tree)
{
	if (tree == NULL)
		return;
	stack<Tree*>s; //创建一个空栈
	Tree* pPre = NULL;
	s.push(tree);
	while (!s.empty())
	{
		tree = s.top();
		if ((tree->Rson == NULL && tree->Rson == NULL) ||
			(pPre != NULL && (tree->Lson == pPre || tree->Rson == pPre)))
		{
			cout << tree->data << " ";
			pPre = tree;
			s.pop();
		}
		else
		{
			if (tree->Rson != NULL)
				s.push(tree->Rson);
			if (tree->Lson != NULL)
				s.push(tree->Lson);
		}
	}
}

vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt->left);
                v.push_back(rt->val);
                rt=rt->right;
            }
            rt=S.top();S.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }