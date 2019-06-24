#include "headfile.h"
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int i,int *find,int last){
        find[i]=-last; // 给它分配为和上一个点不一样的类
        // for(int a=0;a<graph.size();a++)
        // {
        //     cout<<find[a]<<" ";
        // }
        // cout<<endl;
        bool flag=true;
        int j=0;
        while(j<graph[i].size()&&flag)
        {
            // cout<<graph[i][j]<<endl;
            if(find[graph[i][j]]==0)//如果这个点没有被分类，就继续dfs它
            {
                flag=dfs(graph,graph[i][j],find,find[i]);
            }
            else if(find[graph[i][j]]==find[i])//如果这个点已经被分类，如果他和现在的点类别相同，就可以判断不是二分图
            {
                flag=false;
                break;
            }
            j++;
        }
        return flag;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int *find=new int[graph.size()];// 声明一个和点的个数相同的数组 0--未遍历  1--第一类  -1--第二类
        memset(find,0,sizeof(int)*graph.size());//全部初始化为0
        for(int i=0;i<graph.size();i++)//遍历每个顶点，防止图不连通
        {
            if(find[i]==0)
            {
                if(!dfs(graph,i,find,-1)) return false; // 一旦发现不符合二分图的分支，立刻返回
            }
        }
        return true;
    }
};