#include <bits/stdc++.h>
#define MaxSize 100001
using namespace std;
struct Graph
{
	vector<vector<int> > adj;
	int count;
	Graph()
	{
		vector<int> temp;
		for(int i=0;i<MaxSize;i++)
		{
			adj.push_back(temp);
		}
	}
};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		Graph g;
		int indegree[MaxSize]={0};//每一个点的入度
		int n,m;
		cin>>n>>m;
		g.count=n;
		for(int i=0;i<m;i++)
		{
			int temp1,temp2;
			cin>>temp1>>temp2;
			g.adj[temp1].push_back(temp2);
			indegree[temp2]++;
		}
		
		priority_queue<int,vector<int>,greater<int>> que;
		for(int i=1;i<=g.count;i++)
		{
			if(indegree[i]==0)
				que.push(i);
		}
		while(!que.empty())
		{
			int temp=que.top();
			que.pop();
			cout<<temp<<" ";
			for(int j=0;j<g.adj[temp].size();j++)
			{
				if((--indegree[g.adj[temp][j]])==0)
				{
					que.push(g.adj[temp][j]);
				}
			}
		}
		cout<<endl;
	}
}
