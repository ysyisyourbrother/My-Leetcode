#include "headfile.h"
using namespace std;
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        helper(s,0,res);
        return res;
    }
    void helper(string s,int index , vector<string> &res)
    {
        if(index == s.size())
        {
            res.push_back(s);
            return;
        }
        vector<int> judge(128,0); // 用来判断这个字符是否被使用过
        for(int i =index;i<s.size();i++)
        {
            // 逐个交互字符递归
            if(judge[int(s[i])]==1) continue;
            judge[int(s[i])] = 1; // 标记为已经访问过
            swap(s[i],s[index]);
            helper(s,index+1,res);
            swap(s[i],s[index]);// 回溯
        }
    }
};
