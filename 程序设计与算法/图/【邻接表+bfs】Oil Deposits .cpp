#include "headfile.h"
using namespace std;
#define Maxsize 10005
#define infinity 65536
struct node
{
	char a;
	int index;
	node(char x,int y):a(x),index(y){}
};
struct Graph{
	vector<int> adj[Maxsize];
	vector<node> land[105];
	bool visit[Maxsize];
	int count;
	Graph():count(0){}
};
int neighbour[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
void recursion(Graph &g,int s)
{
	g.visit[s]=true;
	for(int i=0;i<g.adj[s].size();i++)
	{
		if(g.visit[g.adj[s][i]]==false)
			recursion(g,g.adj[s][i]);
	}

}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int m,n;
		cin>>m>>n;
		char temp;
		Graph g;
		for(int i=0;i<m;i++)//读整个油矿的地图
		{
			for(int j=0;j<n;j++)
			{
				cin>>temp;
				if(temp=='*')
					g.land[i].push_back(node(temp,-1));
				else
				{
					g.land[i].push_back(node(temp,g.count));//一边读入矩阵一边给@点标号从0开始
					g.count++;//一旦发现了一个油矿节点加一
				}	
			}
		}
		
		for(int i=0;i<g.count;i++) g.visit[i]=false;

		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(g.land[i][j].a=='@')
				{
					for(int k=0;k<8;k++)//探访周围的8个位置是否有@，有的话加入adj矩阵
					{
						int tempx=i+neighbour[k][0];
						int tempy=j+neighbour[k][1];
						if(tempx>=0&&tempx<m&&tempy>=0&&tempy<n&&g.land[tempx][tempy].a=='@')
						{
							g.adj[g.land[i][j].index].push_back(g.land[tempx][tempy].index);
						}
					}
				}
			}
		}

		int result=0;
		for(int i=0;i<g.count;i++)
		{
			if(g.visit[i]==false)
			{
				result++;
				recursion(g,i);
			}
		}

		cout<<result<<endl;
	}
}
