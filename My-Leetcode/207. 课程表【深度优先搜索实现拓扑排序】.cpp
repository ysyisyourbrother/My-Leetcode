#include "headfile.h"
using namespace std;
class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        int indegree[5000]={0};//定义一个收集每个点入度的列表
        if(prerequisites.size()==0)
            return true;
        vector<vector<int> > adj;
        for(int i=0;i<numCourses;i++)//定义一个邻接表
        {
            vector<int> a;
            adj.push_back(a);
        }
        for(int i=0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][0]]++;// 这个顶点入度加一
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);//构建邻接矩阵
        }
        int visit[2005]={0};// 用来标记已经上过的课。当找不到下一个邻节点没被访问过的时候，可以标记为visit=1  出度为0的节点出度最先变成1
        int visit_stack[2005]={0};// 当前路径遍历过的节点，遍历到这个点的路径上的点标记为1
        stack<int> sta;//结点的栈

        //dfs   非递归实现
        for(int start=0;start<numCourses;start++)
        {
            //先找到一个入度为0的顶点才开始遍历。不能只做一次，因为有可能图不连通，入度为0的顶点如果不存在就会一直continue
            if(indegree[start]!=0) continue;
            
            sta.push(start);
            visit_stack[start]=1;
            int tem;
            int i;
            while(!sta.empty())
            {
                tem=sta.top();
                for(i=0;i<adj[tem].size();i++)//遍历每一个邻节点  如果不想每一次都重新遍历，可以加入一个数组记录上次遍历的位置
                {
                    if(visit[adj[tem][i]]==0)// 如果这个课程没有被上过
                    {
                        if(visit_stack[adj[tem][i]]==1)// 如果当前路径发现回边，立刻返回false
                            return false;
                        else//否则入栈并且标记为路径上一点  
                        {
                            sta.push(adj[tem][i]);
                            visit_stack[adj[tem][i]]=1;
                            break;
                        }
                    }
                }
                //当离开循环的条件是所有邻节点都被完全遍历了,就将这个节点从栈和当前路径遍历节点中移除,并用visit标记为已经上过的课程 
                if(i==adj[tem].size())
                {
                    sta.pop();
                    visit_stack[tem]=0;
                    visit[tem]=1;
                }       
            }
        }
        for(int i=0;i<numCourses;i++) //如果有分支是本来就是一个环，就可能不存在入度为0的顶点,它们不会被遍历到
        {
            if(visit[i]==0) return false;
        }
        return true;
    }  
};
int main()
{
	
}