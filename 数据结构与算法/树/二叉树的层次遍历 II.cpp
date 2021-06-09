#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode 
{
    int val;
   TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void reverse(vector<vector<int>> vv)
{
	int i=0,j=vv.size()-1;
	for(;i<j;i++,j--)
	{
		swap(vv[i],vv[j]);
	}
}
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> vv;
    if(root==NULL) return vv;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
    	vector<int> v;
    	int size=que.size();
    	TreeNode *temp;
    	for(int i =0;i<size;i++)
    	{
    		temp=que.front();
	    	v.push_back(temp->val);
	    	que.pop();
	    	if(temp->left!=NULL) que.push(temp->left);
	    	if(temp->right!=NULL) que.push(temp->right);
		}
		vv.push_back(v);
	}
	reverse(vv);
	return vv;
}

int main()
{
	
}
