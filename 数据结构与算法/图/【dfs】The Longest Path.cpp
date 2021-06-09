#include "headfile.h"
using namespace std;
#define Maxsize 1000
struct Graph
{
	vector<int> adj[Maxsize];
	map<int,int> degree;
};
void dfs(Graph &g, int s,int &len,int &Max_len,map<int,bool> &visit)
{
	visit[s]=1;
	len++;
	if(g.degree[s]==1)
	{
		Max_len=Max_len>len?Max_len:len;
	}
	int i;
	for(i=0;i<g.adj[s].size();i++)
	{
		if(!visit[g.adj[s][i]])
		{
			dfs(g,g.adj[s][i],len,Max_len,visit);
		}
	}
	visit[s]=0;
	len--;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		Graph g;
		int m;
		cin>>m;
		if(m==0)
		{
			cout<<"0"<<endl;
			continue;
		} 
		int temp1,temp2;
		map<int,bool> visit;
		map<int,int>::iterator it;
		for(int i=0;i<m;i++)
		{
			cin>>temp1>>temp2;
			g.adj[temp1].push_back(temp2);
			g.adj[temp2].push_back(temp1);
			visit[temp1]=0;
			visit[temp2]=0;

			it = g.degree.find(temp1);
			if(it==g.degree.end())
			{
				g.degree[temp1]=1;
			}
			else g.degree[temp1]++;
			it = g.degree.find(temp2);
			if(it==g.degree.end())
			{
				g.degree[temp2]=1;
			}
			else g.degree[temp2]++;
		}
		int Max_len=0;
		for(it=g.degree.begin();it!=g.degree.end();it++)
		{
			int len=0;
			dfs(g,(*it).first,len,Max_len,visit);
		}
		cout<<Max_len-1<<endl;
	}
}