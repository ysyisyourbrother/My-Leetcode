#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool recursion(TreeNode* subroot,int current,int sum)
{
	bool flag=0;
	current+=subroot->val;
	if((subroot->left==NULL)&&(subroot->right==NULL)&&(current==sum))return 1;
	if(subroot->left!=NULL)
	{
		flag = recursion(subroot->left,current,sum);
	}
	if(flag==0&&subroot->right!=NULL)
	{
		flag = recursion(subroot->right,current,sum);
	}
	return flag;
}
bool hasPathSum(TreeNode* root, int sum) //找出是否存在对应长度路径 
{
	if(root==NULL) return 0;
    return recursion(root,0,sum);
}
void dfs(TreeNode* subroot,int current,int sum,vector<int> v,vector<vector<int>> &vv)
{
	current+=subroot->val;
	v.push_back(subroot->val);
	if((subroot->left==NULL)&&(subroot->right==NULL)&&(current==sum))
	{
		vv.push_back(v);
		return;
	}
	if(subroot->left!=NULL)
	{
		dfs(subroot->left,current,sum,v,vv);
	}
	if(subroot->right!=NULL)
	{
		dfs(subroot->right,current,sum,v,vv);
	}	
 } 
vector<vector<int>> pathSum(TreeNode* root, int sum) //找出所有可能的对应路径 
{
	vector<vector<int>> vv;
	vector<int> v;
	if(root==NULL) return vv;
	
    dfs(root,0,sum,v,vv);
    return vv;
}
int main()
{
	TreeNode a(1);
	TreeNode b(-2);
	TreeNode c(1);
	TreeNode d(-1);
	TreeNode e(1);
	a.left=&b;
	b.left=&c;
	c.left=&d;
	c.right=&e;
	int sum=-1;
	cout << hasPathSum(&a,sum);
}
