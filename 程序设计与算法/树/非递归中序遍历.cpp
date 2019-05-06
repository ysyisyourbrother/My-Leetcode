#include <iostream>
#include <stack>
using namespace std;
template <typename T> 
struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};
template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T &x))
{
	if(root!=NULL)
	{
		inorder_recursive(root->left,visit);
		visit(root->elem);
		inorder_recursive(root->right,visit);
	} 
}
template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x))
{
	stack<BinaryNode<T>* > sta;
	while(root!=NULL||!sta.empty())
	{
		if(root!=NULL)
		{
			sta.push(root);
			root=root->left;
		}
		else
		{
			BinaryNode<T>* temp=sta.top();
			sta.pop();
			visit(temp->elem);
			root=temp->right;
		}
	}	
}
int main()
{
	
}
