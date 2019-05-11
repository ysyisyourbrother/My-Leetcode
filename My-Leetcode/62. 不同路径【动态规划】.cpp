#include "headfile.h"
using namespace std;
class Solution {
public:
    /*动态规划来求解，们可以维护一个二维数组dp，其中dp[i][j]表示到当前位置不同的走法的个数，
    然后可以得到递推式为: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，
    这里为了节省空间，我们使用一维数组dp，一行一行的刷新也可以*/
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; 
            }   
        }
        return dp[n - 1];
    }
    /*排列组合求解：实际相当于机器人总共走了m + n - 2步，其中m - 1步向右走，n - 1步向下走
    那么总共不同的方法个数就相当于在步数里面m - 1和n - 1中较小的那个数的取法，实际上是一道组合数的问题*/
    int uniquePaths2s(int m, int n) {
        double num = 1, denom = 1;
        int small = m > n ? n : m;
        for (int i = 1; i <= small - 1; ++i) {
            num *= m + n - 1 - i;
            denom *= i;
        }
        return (int)(num / denom);
    }
};
int main()
{
	
}