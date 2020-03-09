# include "headfile.h"
using namespace std;
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int> >judge(m,vector<int>(n,0));
        return bfs(0,0,m,n,k,judge);
    }
    int bfs(int x, int y,int m, int n, int k,vector<vector<int> >&judge)
    {
        if(!(x>=0 && x<m && y>=0 && y<n))
            return 0;
        if((x%10+x/10+y%10+y/10)>k)
            return 0;
        if(judge[x][y]==-1)
            return 0;
        judge[x][y]=-1; // 标记当前位置为已访问过
        return 1 + bfs(x+1,y,m,n,k,judge)+bfs(x,y+1,m,n,k,judge);
    }
};