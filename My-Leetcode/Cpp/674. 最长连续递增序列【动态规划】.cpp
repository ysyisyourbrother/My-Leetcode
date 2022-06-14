#include "headfile.h"
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int dp[10005];// 动态规划，也可以不用开数组直接用一个count记录dp[i-1]的值
        dp[0]=1;
        int res=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                dp[i]=dp[i-1]+1;
            else
            {
                res=res>dp[i-1]?res:dp[i-1];
                dp[i]=1;
            }
        }
        res=res>dp[nums.size()-1]?res:dp[nums.size()-1];
        return res;
    }
};