#include "headfile.h"
using namespace std;
/*
将连在一起的土地，直接通过 DFS/BFS 全部标记一遍。最后看有几个没有连在一起的土地集群即可。 思路就是 for 循环各个字符，每一次循环时，采用 fooldfill 算法感染全部与当前遍历的 [x][y] 相连的土地。 最后看看 for 循环了几次即可。 
 */
class Solution {
public:
    bool isLegal(int h,int w,int i,int j)
    {
        return i>=0&&i<h&&j>=0&&j<w;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& found,int i,int j)
    {
        found[i][j]=1;//标注为已经访问过的大陆
        int h=grid.size();
        int w=grid[0].size();
        if(isLegal(h,w,i-1,j)&&grid[i-1][j]=='1'&&found[i-1][j]==0) 
            dfs(grid,found,i-1,j);
        if(isLegal(h,w,i+1,j)&&grid[i+1][j]=='1'&&found[i+1][j]==0) 
            dfs(grid,found,i+1,j);
        if(isLegal(h,w,i,j-1)&&grid[i][j-1]=='1'&&found[i][j-1]==0) 
            dfs(grid,found,i,j-1);
        if(isLegal(h,w,i,j+1)&&grid[i][j+1]=='1'&&found[i][j+1]==0) 
            dfs(grid,found,i,j+1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int height=grid.size();
        int width=grid[0].size();
        //定义一个空的数组做标注
        vector<vector<int>> found;
        int res=0;//定义一个最终要返回的大陆数量
        for(int i=0;i<height;i++)
        {
            vector<int> tem(width,0);
            found.push_back(tem);
        }
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(found[i][j]==0&&grid[i][j]=='1')//如果有陆地且没有遍历到，就用搜索算法遍历标注相邻的陆地为found=1
                {
                    dfs(grid,found,i,j);
                    res++;//每次找到一片大陆 数量加一，并且把相邻的都标注，再继续循环
                }
            }
        }
        return res;
    }
};