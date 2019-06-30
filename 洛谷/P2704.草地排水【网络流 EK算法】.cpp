#include "headfile.h"
/*
    网络流的EK算法  使用标号法
*/
using namespace std;
int parent[205];//记录一次广搜每个增广路的节点的父节点
int alpha[205];//记录当前增广路剩余可增广容量（标号）
int main()
{
    int N,M,Si,Ei,Ci;
    int result=0;// 最后要返回的最大流量值
    int capacity[205][205];// 定义一个管道容量的邻接矩阵
    int flow[205][205];//定义一个当前流的邻接矩阵
    memset(capacity,0,sizeof(capacity));// 容量初始化为0
    memset(flow,0,sizeof(flow));// 流初始化为0 从0流开始
    scanf("%d%d",&N,&M); //N是边数M是顶点的数量
    int m=M-1;//终点的编号
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d",&Si,&Ei,&Ci);// 原点 终点 管道最大容量
        Si--,Ei--;//点的编号从0开始，所以要减1
        capacity[Si][Ei]+=Ci; // 容量是一个有向边，而且要注意有可能有重边
    }
    //广度优先搜索查找可增广路
    do{
        result+=alpha[m];
        memset(alpha,0,sizeof(alpha)); // 每次都要清空标号 因为它同时也当做是否被加入增广路的条件
        alpha[0]=INT_MAX;
        queue<int> q;
        q.push(0);//加入广搜起点
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            for(int i=0;i<M;i++)
            {
                //alpha可以判断这个点是否在一条曾广路上
                //后面两个条件不可能同时成立， 如果这是一条反向边，如果反向流大于0就说明这条边的端点有可以调整的流量。如果这是一条正向边，容量大于流量，说明这条边的端点可调整流量。任意满足一个就可以进入内部判断。
                if(!alpha[i]&&(capacity[top][i]>flow[top][i]||flow[i][top]>0))
                {
                    parent[i]=top;//标记这个节点的父节点标号
                    //二者一定是其中一个为0另外一个为一个大于0的正数，或者同时为0。 因此可以直接用max来算，也可以分类讨论
                    // alpha[i]=min(alpha[top],max(capacity[top][i]-flow[top][i],flow[i][top]));
                    if(capacity[top][i]>flow[top][i])//如果是正向弧 用正向边剩余容量更新
                        alpha[i]=min(capacity[top][i]-flow[top][i],alpha[top]);
                    else// 反向弧 用反向边的值来更新
                        alpha[i]=min(flow[i][top],alpha[top]);
                    q.push(i);
                    
                }
            }
        }
        if(alpha[m] == 0 )// 广搜没有发现增广路 到m点的时候可调整容量为0 输出并返回
        {
            return printf("%d\n",result),0;
        }
        // 可调整容量不为0  从后往前更新每条边的值
        for (int i=m;i>0;i=parent[i])// i每次变成parent[i]的值
        {
            if(capacity[parent[i]][i]>flow[parent[i]][i])//如果是正向弧 加上增加的流量
                flow[parent[i]][i]+=alpha[m];
            else// 反向弧 减去可以减少的流量
                flow[i][parent[i]]-=alpha[m];
        }
    }while(1);
    return printf("%d\n",result),0;
}