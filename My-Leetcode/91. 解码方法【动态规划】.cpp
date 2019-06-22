#include "headfile.h"
using namespace std;
// 简单动态规划  dp[i] = dp[i-1]+dp[i - 2];
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) return 0; // 如果是空的或者第一个就是0
        vector<int> dp(s.size()+1, 0);//dp[i] 中的i表示到第几个字符的可能组合数 定义空串的组合数是1，这样就不用再单独讨论i=2的情况了
        dp[0] = 1,dp[1]=1;
        for (int i = 1; i < s.size()+1; ++i) {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};  