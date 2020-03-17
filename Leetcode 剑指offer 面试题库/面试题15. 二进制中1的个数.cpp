#include "headfile.h"
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
		// 一位一位判断是1还是0
        int ret = 0;
        for (int i = 0; i < 32; i ++) {
            if (n & (1 << i)) {
                ret ++;
            }
        }
        return ret;
    }
};
