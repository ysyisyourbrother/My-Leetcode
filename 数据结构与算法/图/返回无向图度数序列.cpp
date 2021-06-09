#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct  ALGraph{
    vector<vector<int> > adj; //adjacency list of the graph
    int order;// number of vertices
    int size;//number of edges

    //A  simple initialization.
   ALGraph(int n=0, int m=0):order(n), size(m){
        adj.resize(n);
   }
} ;

ALGraph mkGraph()
{
	int n,m;
	cin>>n>>m;
	int a,b;
	ALGraph g(n,m);
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g.adj[a].push_back(b);
		g.adj[b].push_back(a);
	}
	return g;
}
bool cmp(int a,int b)
{
	return a>b;
}
//假定n个结点分别用0,1,..., n-1表示。例如，3个结点的无向图的结点分别是0,1和2.
vector<int> degreeSequence(const ALGraph &g)
{
	vector<int> vec;
	int count=0;
	for(int i=0;i<g.order;i++)
	{
		vec.push_back(g.adj[i].size());
	}
	sort(vec.begin(),vec.end(),cmp);
	return vec;
}
int main()
{
	ALGraph g = mkGraph();
	vector<int> temp = degreeSequence(g);
	for(int i=0;i<temp.size();i++)
	{
		cout<<temp[i]<<" "; 
	}
}
