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
        int indegree[5000]={0};
        for(int i=0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][0]]++;// 这个顶点入度加一
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);//构建邻接矩阵
        }
        //bfs
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
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
                indegree[adj[tem][i]]--;
                if(indegree[adj[tem][i]]==0)
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