#include "headfile.h"
using namespace std;
class Solution {
public:
    // 原地操作版本，将后面的字符往前面移动
    string reverseLeftWords(string s, int n) {
        if(s.size()==0) return s;
        string tmp = s.substr(0,n);
        moveString(s,n);
        s.replace(s.size()-n,n,tmp);
        return s;
    }
    void moveString(string &s, int n)
    {
        // 定义函数将字符串s的n位置后的字符向左移动n位
        for(int i = n;i<=s.size();i++)
        {
            s[i-n] = s[i];
        }
    }
};