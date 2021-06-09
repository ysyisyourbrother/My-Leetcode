#include <iostream>
#include <string>
using namespace std;
template <typename T> 
struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};
template <typename T>
void recursion(string &preorder,string inorder,BinaryNode<T>* &root,bool flag)
{
	if(preorder==""||inorder=="") return;
	BinaryNode<T>*Node=new BinaryNode<T>(preorder[0]);
	preorder.erase(preorder.begin());//删除使用过的元素 
	if(root!=NULL)//和根节点相连  左0右1 
	{
		if(flag==0)
			root->left=Node;
		else
			root->right=Node;
	}
	else
		root=Node;
		
	int i;
	for(i=0;i<inorder.size();i++)
	{
		if(inorder[i]==Node->elem)
			break;
	}
	if(i==0&&i!=inorder.size()-1)
	{
		recursion(preorder,inorder.substr(i+1),Node,1); 
	}
	else if(i!=0&&i==inorder.size()-1)
	{
		recursion(preorder,inorder.substr(0,i),Node,0);
	}
	else if(i!=0&&i!=inorder.size()-1)
	{
		string subleft=inorder.substr(0,i);
		string subright=inorder.substr(i+1);
		recursion(preorder,subleft,Node,0);
		recursion(preorder,subright,Node,1); 
	}
	
}
BinaryNode<char>* buildTree(const string &preorder, const string &inorder)
{
	string temp=preorder;
	BinaryNode<char>* root=NULL;
	recursion(temp,inorder,root,0);
	return root;
}
void print(BinaryNode<char>* root)
{
	if(root!=NULL)
	{
		print(root->left);
		cout<<root->elem;
		print(root->right);
	}
}
int main()
{
	print(buildTree("bfdgaec","abdfgce"));
}

