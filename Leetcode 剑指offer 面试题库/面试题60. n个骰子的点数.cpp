#include "headfile.h"
using namespace std;
class Solution {
public:
    // 使用动态规划的方法实现，定义一个二维的备忘录，横坐标是几个骰子，纵坐标是和为多少
    vector<double> twoSum(int n) {
        vector<double> res;
        if(n==0) return res;

        // 和的取之范围为1-6n
        vector<vector<int> > dp(n, vector<int>(6*n,0));
        // 初始化备忘录，将n=1的情况下的1-6定义为1
        for(int i=0;i<6;i++)
            dp[0][i]=1;

        //从n=2开始计算到n的情况
        for(int count = 2;count<=n;count++)
        {
            for(int sum=count;sum<=6*count;sum++) // 从n遍历到6n
            {
                for(int i =1;i<=6;i++)
                {
                    if(sum-i<1) // 如果数组越界 结束循环
                        break;
                    dp[count-1][sum-1] += dp[count-2][sum-i-1];
                }
            }
        }
        int total = pow(6,n);
        for(int i = n;i<=6*n;i++)
        {
            res.push_back(double(dp[n-1][i-1])/total);
        }
        return res;
    }
};