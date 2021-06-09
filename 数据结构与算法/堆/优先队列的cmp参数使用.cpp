#include "headfile.h"
using namespace std;
struct Node
{int adj;
 int val;
 Node(int x):val(x){}
};
struct cmp
{bool operator()(Node a,Node b) { return  a.val > b.val; }
};

int main()
{
	priority_queue<Node,vector<Node>,cmp>Q; 
	Node a(4);
	Node b(6);
	Node c(2);
	Q.push(a);
	Q.push(b);
	Q.push(c);
	for(int i=0;i<3;i++)
	{
		cout<<Q.top().val<<' ';
		Q.pop();
	}
}