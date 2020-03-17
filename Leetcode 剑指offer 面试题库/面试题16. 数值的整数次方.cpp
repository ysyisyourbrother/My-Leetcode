#include "headfile.h"
using namespace std;
class Solution {
public:
    //题解：快速幂
    double myPow(double base, int n) {
        double res=1.0;
        int i=n;
        while(i){
            if(i&1)res*=base;  //i的低位存在，res*x
            base*=base;           //base扩大为它的平方，因为n要左移一位，所以之后最低位变为base^2
            i/=2;           //i右移一位
        }
        return n<0?1/res:res;
    }
};