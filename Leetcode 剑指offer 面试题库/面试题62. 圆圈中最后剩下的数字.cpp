#include "headfile.h"
using namespace std;
class Solution {
public:
    // 约瑟夫环，使用数学推倒的方法求解 https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
    int lastRemaining(int n, int m) {
        int a = 0;
        for(int i=2;i<=n;i++) // 用迭代备忘录的方法计算 f(2,m) 到f(n,m)的值
        {
            a = (a+m)%i;  // mod i 是因为此时只有i个人
        }
        return a;
    }
};