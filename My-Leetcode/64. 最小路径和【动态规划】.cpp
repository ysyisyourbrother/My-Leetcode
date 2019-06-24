#include "headfile.h"
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        vector<int> dp(grid[0]);// 只需要一个数组的dp 初始化为grid的第一行
        for(int i=1;i<dp.size();i++)
            dp[i]+=dp[i-1];
        for(int i=1;i<grid.size();i++)//逐行遍历
        {
            dp[0]+=grid[i][0];// 因为第i行的第一个永远是从左上角直下是最小的
            for(int j=1;j<grid[0].size();j++)//每一行中逐个遍历更新
            {
                dp[j]=grid[i][j]+(min(dp[j-1],dp[j]));
            }
        }
        return dp.back();// 最后返回最后一个元素
    }
};