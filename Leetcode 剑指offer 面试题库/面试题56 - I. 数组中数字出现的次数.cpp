#include "headfile.h"
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 本题本质上是结合了另外两个位运算题目的思想
        // 我们的目标是将nums分为两组，只出现了一次的两个数分别在不同的一组，然后所有相同的数要分在同一组
        // 这样只需要对每个组分别用异或就可以的到结果了
        // 先对nums进行分组
        int all_xor=0;
        for(auto num : nums)  // 先对所有数进行异或操作
            all_xor ^= num; 

        //随便选择一位不为0的位，这一位说明只出现1次的两个数在这一位是可以被划分到不同组的的。按照这一位为0或者为1 分组，就可以满足上诉条件
        int h =1;
        while((h&all_xor)==0)
            h = h<<1;
        cout<<h;
        vector<int> res(2,0); // 定义答案数组，分成两组
        for(auto num:nums) // 遍历所有数 按照对应的组进行异或 最后剩下的结果就是答案
        {
            if((h&num)!=0)
                res[1] ^= num;
            else
                res[0]^=num;
        }
        return res;
    }
};