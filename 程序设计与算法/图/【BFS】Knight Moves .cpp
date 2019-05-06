#include "headfile.h"
using namespace std;
#define Maxsize 150
#define infinity 65536
//骑士周游世界问题 骑士在棋盘上走，每次只能跳一个日字，求从一个格子到另外一个格子最小跳日字次数
struct node
{
	int x,y;
	int count;
	node(int a,int b,int c):x(a),y(b),count(c){}
};
int Move[8][2]={{1,-2},{2,-1},{2,1},{1,2},//马走日的八个方向.
    			{-1,2},{-2,1},{-2,-1},{-1,-2}};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int ex,ey;//the coordinate of end point
		bool chessboard[8][8];
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				chessboard[i][j]=false;
			}
		}
		char str1[3];
		char str2[3];
		scanf("%s%s",str1,str2);
		ex=str2[0]-'a';
		ey=str2[1]-'0'-1;
		queue<node> que;//the queue of node to do bfs
		node tem(str1[0]-'a',str1[1]-'0'-1,0);//build the start node
		que.push(tem);
		chessboard[tem.x][tem.y]=true;

		while(!que.empty())//begin the bfs algorithm
		{
			node temp=que.front();
			que.pop();
			if(temp.x==ex&&temp.y==ey) 
			{
				cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<temp.count<<" knight moves."<<endl;
				continue;
			}
			for(int i=0;i<8;i++)//find the next node and push into queue
			{
				int x=temp.x+Move[i][0];
				int y=temp.y+Move[i][1];
				if(x>=0&&x<8&&y>=0&&y<8&&chessboard[x][y]==false)
				{
					chessboard[x][y]=true;
					que.push(node(x,y,temp.count+1));
				}
			}
		}
		
	}
}