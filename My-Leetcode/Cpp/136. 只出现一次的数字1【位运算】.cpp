#include "headfile.h"
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 任何数字和本身异或是0，和0异或是本身，因此直接异或就可以做出
        int res = 0;
        for(auto i : nums)
            res^i;
        return res;
    }
};