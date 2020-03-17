#include "headfile.h"
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
		if(grid.size()==0 || grid[0].size()==0) return 0; // 判断特殊情况单独讨论
		int m = grid.size();
		int n = grid[0].size();
		// 定义动态规划数组
		vector<vector<int> > dp(m+1, vector<int>(n+1,0));// 定义多一圈，可以减少判断

		for(int i = 1 ;i<=m;i++)
		{
			for(int j =1;j<=n;j++)
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
			}
		}
		return dp[m][n];
    }
};