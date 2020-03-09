#include "headfile.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128]={0}; // 哈希映射上一个这个字符的位置
        vector<int> res(1,0); // 动态规划 初始化第一个为0
        for(int i=1;i<=s.size();i++)
        {
            char cur = s[i-1];// 当前的字符
            // 找当前字符的上一个位置
            int last = hash[int(cur)];
            hash[int(cur)] = i;
            // 计算新的连续不重复串的起始位置
            int start = max(i-1-res[i-1]+1,last+1);
            res.push_back(i-start+1);
        }
        return *max_element(res.begin(), res.end());
    }
};