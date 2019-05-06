#include <iostream>
#include <queue>
using namespace std;
struct BinaryNode
{
    string name;
    int size;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode( const string & n = "", int s = 0, BinaryNode *lt =NULL, BinaryNode *rt =NULL )
        : name(n), size(s), left( lt ), right( rt ) { };
};
int height(const BinaryNode* root)
{
	if(root==NULL)
		return -1;
	int height=-1,count;//根的高度从0开始算 
	queue<BinaryNode*> q;
	q.push((BinaryNode*)root);
	while(!q.empty())
	{
		BinaryNode *temp;
		count=q.size();
		height++;
		for(int i=0;i<count;i++)
		{
			temp=q.front();
			q.pop();
			if(temp->left!=NULL) q.push(temp->left);
			if(temp->right!=NULL) q.push(temp->right);
		}	
	}
	return height;
}
int main()
{
	
}
