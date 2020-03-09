# 贪心算法，其实也是找规律方法 一般情况下剪的越多值越大 ·
class Solution:
    def cuttingRope(self, n: int) -> int:
        if n <= 3: return n - 1
        a, b = n // 3, n % 3
        if b == 0: return 3 ** a
        if b == 1: return 3 ** (a - 1) * 4 # 3*1<2*2
        return 3 ** a * 2

# 动态规划的方法，对每一个n，遍历所有可能的剪法，剪完剩下的部分分为剪还是不剪，取最大值
class Solution1:
    def cuttingRope(self, n: int) -> int:
        dp = [0 for _ in range(n + 1)]  # dp[0] dp[1]其实没用
        dp[2] = 1  # 初始化
        res = -1
        for i in range(3, n + 1):
            for j in range(i):
                dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]))
        return dp[n]

