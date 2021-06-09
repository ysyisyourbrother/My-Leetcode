/*˼·:  
1 �ҵ���ȫ������������ڵ㣬Ҳ����������������� 
2 �ҵ���ȫ������ͷ�ڵ��������е�����ڵ㣬��¼��������� 
3 ������������ȣ�˵��ͷ�ڵ���������һ������������ʹ�ù�ʽ��ó����ټ���ͷ�ڵ㣬Ȼ�����������ʹ�õݹ���� 
4 �����������ȴ�����������ȣ�˵����������һ����ȫ��������ʹ�ù�ʽ��ó����ټ���ͷ�ڵ㣬Ȼ�����������ʹ�õݹ����.
*/
  struct TreeNode {
      int val;
    TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
int countNodes(TreeNode* root) 
{
	int count=0;
	int ldepth=0,rdepth=0;
	if(root==NULL) return 0;
	TreeNode* cur;
	cur=root->left;
	while(cur!=NULL)
	{
		ldepth++;
		cur=cur->left;//����������������� 
	}
	cur=root->right;
	while(cur!=NULL)
	{
		rdepth++;
		cur=cur->left;//����������������� 
	}
	if(ldepth==rdepth)//������Ϊ�����������ݹ���������� 
	{
		count = pow(2, ldepth) - 1 + countNodes(root->right) + 1;//����һ���ϸ� 
	}
	else//���������������߶���һ����������� ���ݹ���������� 
	{
		count = pow(2, rdepth) - 1 + countNodes(root->left) + 1;
	}
	return count;
}
};
