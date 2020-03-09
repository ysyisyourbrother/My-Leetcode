#include "headfile.h"
using namespace std;
class Solution {
public:
    // 使用数学解法，用求和公式+因式分解
    // (start+end)(end-start+1) = target*2
    vector<vector<int>> findContinuousSequence(int target) {
        vector <vector<int>> ans;
        target*=2;
        for(int i=target/2-1;i>=2;i--)// 因式分解只用遍历到原来的target即可 这里的target是乘了2倍的  去掉i = 1的情况
        {
            if(target%i==0 && ((i%2)^(target/i%2)))// 如果i整除target 并且 i 和target/i 为不同的奇偶，此时是一个正确的分解
            {
                int start = (target/i-i+1)/2,end = (target/i+i-1)/2; // 计算start和end
                if(start<=0) // 如果start 不满足要求 跳过这种情况
                    continue;
                // 如果满足要求，加入到答案中
                vector<int> tmp;
                for(int j=start;j<=end;j++)
                    tmp.push_back(j);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};