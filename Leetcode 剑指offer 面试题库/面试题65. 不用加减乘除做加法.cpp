#include "headfile.h"
using namespace std;
class Solution {
public:
    int add(int a, int b) {
        if(b==0)
            return a;
        int step1=0, step2=0;
        while(b!=0){
        	step1 = a^b; // 计算不进位结果
	        step2 = (unsigned int)((a&b))<<1; // 计算进位情况 此时问题相当于不进位结果加进位情况 step1+step3
            //LeetCode中国版的C++不支持负值左移 要转换类型为无符号数
	        a = step1;
	        b = step2;
		}
        return step1;
    }
};