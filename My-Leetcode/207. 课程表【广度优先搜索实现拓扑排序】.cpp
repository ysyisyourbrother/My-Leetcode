#include "headfile.h"
using namespace std;
class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        if(prerequisites.size()==0)
            return true;
        vector<vector<int> > adj;
        for(int i=0;i<numCourses;i++)
        {
            vector<int> a;
            adj.push_back(a);
        }
        int indegree[5000]={0}; //定义一个收集每个点入度的列表
        for(int i=0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][0]]++;// 这个顶点入度加一
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);//构建邻接矩阵
        }
        //bfs
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)// 将所有入度为0的顶点加入队列中
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int tem=q.front();
            q.pop();
            for(int i=0;i<adj[tem].size();i++)
            {
                indegree[adj[tem][i]]--; // 将邻接课程的入度都减一 然后才能把当前课程标记为已经上过
                if(indegree[adj[tem][i]]==0)// 如果邻接课程入度减1后变成了0，就可以在加入队列
                    q.push(adj[tem][i]);        
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]!=0)
                return false;
        }
        return true;
    }
};
int main()
{
	
}