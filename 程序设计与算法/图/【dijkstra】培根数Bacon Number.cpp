#include "headfile.h"
using namespace std;
#define Maxsize 150
#define infinity 65536
struct Graph
{
	vector<int> adj[Maxsize];
	set<int> S;//the set of vertices
};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		Graph g;
		int m;
		cin>>m;
		if(m!=0)
		{
		int temp1,temp2;
		for(int i=0;i<m;i++)
		{
			cin>>temp1>>temp2;
			g.adj[temp1].push_back(temp2);
			g.adj[temp2].push_back(temp1);
			g.S.insert(temp1);
			g.S.insert(temp2);
		}
		bool visit[Maxsize];
		int distance[Maxsize];
		for(int i=0;i<Maxsize;i++) 
		{
			visit[i]=false;
			distance[i]=infinity;
		}
		for(int i=0;i<g.adj[0].size();i++)
		{
			distance[g.adj[0][i]]=1;
		}
		visit[0]=true;
		for(int i=0;i<g.S.size();i++)//dijkstra algorithm begin run n times
		{
			int min=infinity;
			int v=0;
			for(int j=0;j<Maxsize;j++)
			{
				if(!visit[j]&&distance[j]<min)
				{
					v=j;
					min=distance[j];
				}
			}
			visit[v]=true;
			for(int j=0;j<g.adj[v].size();j++)
			{
				if(!visit[g.adj[v][j]]&&distance[g.adj[v][j]]>distance[v]+1)
				{
					distance[g.adj[v][j]]=distance[v]+1;
				}
			}
		}
		set<int>::iterator it = g.S.begin();
		int temp;
		for(it++;it!=g.S.end();it++)
		{
			temp=*it;
			cout<<temp<<":"<<distance[temp]<<endl;
		}
		}
		cout<<"---"<<endl;
		
	}
}