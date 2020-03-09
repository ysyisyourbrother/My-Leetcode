#include "headfile.h"
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0) return 0;
        vector<int> res; // 动态规划的方法 三指针
        res.push_back(1);// 1 为丑数
        int p=0,q=0,r=0;
        while(res.size()<n)
        {
            int next = min(res[p]*2,res[q]*3); //下一个丑数，选三者最小的一个
            next = min(res[r]*5,next);
            res.push_back(next);
            // 将指向最小数的指针向后移动，注意有可能有多个最小数
            if(next == res[p]*2)
                p++;
            if(next == res[q]*3)
                q++;
            if(next == res[r]*5)
                r++;
        }
        return res[n-1];
    }
};