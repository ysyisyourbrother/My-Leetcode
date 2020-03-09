#include "headfile.h"
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int pre = nums[0]; //上一个数
        int cur;
        int res = nums[0]; // 最大值
        for(int i =1;i<nums.size();i++)
        {
            cur = nums[i];
            if(pre<=0)
            {
                res = max(res,cur);
                pre = cur;
                continue;
            }
            else
            {
                res = max(res,cur+pre);
                pre = cur+pre;
            }
        }
        return res;
    }
};