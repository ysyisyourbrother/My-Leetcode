#include "headfile.h"
using namespace std;

class Solution {
public:
    // 字符串排序算法
    string minNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(),nums.end(),[](int a, int b ){ return to_string(a)+to_string(b)<to_string(b)+to_string(a);});
        for(auto num : nums)
        {
            res+=to_string(num);
        }
        return res;
    }
};