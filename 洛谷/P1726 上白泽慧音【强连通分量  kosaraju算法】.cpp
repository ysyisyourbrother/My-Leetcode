#include "headfile.h"
using namespace std;
vector<vector<int> > mat;// 邻接表
vector<vector<int> > rmat;// 反邻接表
stack<int> sta; // 收集伪拓扑排序
int found[5001];// 检查是否被发现过

void dfs(int x)// 建立伪拓扑序列
{
    found[x]=1;
    for(int i=0;i<rmat[x].size();i++)
    {
        if(found[rmat[x][i]]==1) continue;  // 如果这个点已经被访问过了 就继续查看下一个邻点
        dfs(rmat[x][i]); 
    }
    sta.push(x);  // 压入伪拓扑序列中
}
void dfs2(int x,vector<int>& new_village)// 寻找强连通分量并标记经过的点
{
    found[x]=1;
    new_village.push_back(x);   
    for(int i=0;i<mat[x].size();i++)
    {
        if(found[mat[x][i]]==1) continue;  // 如果这个点已经被访问过了 就继续查看下一个邻点
        dfs2(mat[x][i],new_village); 
    }
}
int main()
{
    int N,M;
    int tem1,tem2,tem3;
    cin>>N>>M; // N个村庄和M个道路
    for(int i=0;i<N;i++) // 初始化邻接表
    {   
        vector<int> tem;
        mat.push_back(tem);
        rmat.push_back(tem);
    }
    for(int i=0;i<M;i++) // 读入数据建立邻接表
    { 
        scanf("%d%d%d",&tem1,&tem2,&tem3);
        if(tem3==1)// 从tem1到tem2的单向路
        {
            mat[tem1-1].push_back(tem2-1); 
            rmat[tem2-1].push_back(tem1-1);// 构建GR
        }
        else{// 从tem1到tem2的双向路 构建GR的方法一样
            mat[tem1-1].push_back(tem2-1); 
            mat[tem2-1].push_back(tem1-1); 
            rmat[tem1-1].push_back(tem2-1); 
            rmat[tem2-1].push_back(tem1-1); 
        }
    }

    // 深度优先搜索建立伪拓扑排序
    for(int i=0;i<N;i++)
    {
        if(found[i]==1) continue;
        dfs(i);
    }
    // 对原图按照stack的拓扑顺序开始深度优先搜索遍历查找分量
    memset(found,0,sizeof(int)*N);// 初始化found数组为0
    vector<int> village;// 最大数量的强连通分量的村庄  （按照字典序排序）
    while(!sta.empty())
    {
        if(found[sta.top()]==1) 
        {
            sta.pop();// 如果已经被访问过就pop并继续寻找
            continue;
        }    
        vector<int> new_village;// 现在正在遍历的强连通分量的村庄序列
        int cur=sta.top();
        dfs2(cur,new_village);
        if(new_village.size()>=village.size())
        {
            sort(new_village.begin(),new_village.end());// 对新建立的村庄向量进行排序
            if(new_village.size()==village.size())
            {
                for(int i=0;i<village.size();i++)
                {
                    if(new_village[i]<village[i])// 比较字典序的大小，小的会被选为最优解
                    {
                        village=new_village;
                        break;
                    }
                }
            }
            else
                village=new_village;
        }
    }
    printf("%d\n",village.size());
    for(int i=0;i<village.size();i++)
    {
        printf("%d ",village[i]+1);
    }
    printf("\n");
}