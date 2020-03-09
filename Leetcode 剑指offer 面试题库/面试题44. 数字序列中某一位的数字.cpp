#include "headfile.h"
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        // 先通过遍历找到数字n是在第几个区间
        int level = 0; // 记录n属于几位数的区间
        if(n==0) return 0; // 单独讨论第一种情况
        long count_sum = 0; // 从1开始计算总位数
        long base = 1;
        while(count_sum<n)
        {
            level+=1;
            count_sum += 9*base*level;
            base*=10;
        }
        // 如果count_sum >=m 说明找到了区间level 也就是level位数的区间内
        int diff = (count_sum - n)/level; // 得到大了多少个数
        int diff_index = (count_sum - n)%level; // 在这个数中偏移几位
        
        int target = pow(10, level) - 1 - diff; // 得到第n位所在的数字
        while(diff_index--)
            target/=10;
        return target%10;
    }
};