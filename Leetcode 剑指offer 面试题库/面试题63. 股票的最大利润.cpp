#include "headfile.h"
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if(days<=1) return 0;

        vector<int> dp(days,0);
        for(int i=days-2;i>=0;i--)
            dp[i] = max(dp[i+1],prices[i+1]);
        int res=0;
        for(int i=0;i<days-1;i++)
            res = max(res, dp[i]-prices[i]);
        return res;
    }
};