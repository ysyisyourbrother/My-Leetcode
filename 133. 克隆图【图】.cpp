#include "headfile.h"
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
	Node* connectNode(Node *last,Node* node,vector<Node*> &f)
	{
		vector<Node*>::iterator result = f.begin();
		for(;result!=f.end();result++)
		{
			if((*result)->val==node->val)
			{
				break;
			}
		}
		if(result!=f.end())
		{
			last->neighbors.push_back((*result));//相互之间连边
			return NULL;
		}
		//如果节点不存在 则建立节点
		Node *temp = new Node;
		f.push_back(temp);
		temp->val=node->val;
		last->neighbors.push_back(temp);//相互之间连边
		return temp;
	}
	void recursion(Node *new_graph,Node*ori_graph,vector<Node*> &f)
	{
		Node *temp;
		for(int i=0;i < ori_graph->neighbors.size();i++)
		{
			if(temp = connectNode(new_graph,ori_graph->neighbors[i],f))
			{
				recursion(temp,ori_graph->neighbors[i],f);
			}
		}
	}
    Node* cloneGraph(Node* node) 
	{
		if(node == NULL) return NULL;
		vector<Node*> f;//已经建立的节点
        Node *new_graph = new Node; // 新的图的第一个节点

        f.push_back(new_graph);
		new_graph->val = node->val;
		recursion(new_graph,node,f);
        return new_graph;
    }
};
int main()
{
	//https://github.com/ysyisyourbrother/Leetcode.git
}