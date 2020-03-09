class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 还是使用位运算，一位位的判断是否不止3个一样的，如果不止，则说明res在这个位置上为1
        int res = 0;
        unsigned int bit = 0; // 当前位，比如第一位就是0000000000001
        for(int i =0;i<32;i++) // 遍历32位，一位位判断
        {
            bit = 1 << i; // 1左移i位 找到当前操作的位数
            // 遍历nums中的所有数
            int cnt = 0;
            for(auto num : nums)
            {
                if ((num&bit)!=0) // 如果不为0 ，则cnt++ 这里注意要有括号，位运算的优先级很低
                    cnt++;
            }
            
            if(cnt%3!=0) // 如果不止3个，说明res在这个位为1
                res = res|bit;
        }
        return res;
    }
};