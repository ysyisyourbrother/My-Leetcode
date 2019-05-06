#include <iostream>
#include <queue>
using namespace std;
typedef int T;
struct treeNode {
  T data;
  treeNode *left, *right;
 
  treeNode(T d, treeNode *l=NULL, treeNode *r=NULL):data(d),left(l),right(r){};
};
     
int width(const treeNode * root)
{
	if(root==NULL)
	{
		return 0;
	}
	queue<treeNode *> q;
	int maxwidth=0;
	q.push((treeNode *)root);
	while(!q.empty())
	{
		int count=q.size();
		maxwidth = count > maxwidth ? count : maxwidth;
		for(int i=0;i<count;i++)
		{
			treeNode* temp=q.front();
			q.pop(); 
			if(temp->left!=NULL)
			{
				q.push(temp->left);
			}
			if(temp->right!=NULL)
			{
				q.push(temp->right);
			}
		}
	}
	return maxwidth;
}
int main()
{
	treeNode a(1);
	treeNode b(2);
	treeNode c(3);
	treeNode d(4);
	treeNode e(5);
	treeNode f(6);
	a.left=&b;
	a.right=&e;
	b.right=&c;
	b.left=&d;
	e.left=&f;
	cout<<width(&a);
 } 
