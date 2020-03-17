#include "headfile.h"
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return s;
        int len = 0;
        string ans = "";
        for(int m = s.size()-1; m >=0; m--)
        {
            if(s[m]==' '&&len!=0) // 判断是否找到一个单词
            {
                ans += s.substr(m+1,len)+ " ";len = 0; continue;
            }
            if(s[m]!= ' ')len++;  
        }
		// 将最后一个单词加入结果，并去掉最后一个空格
        if(len !=0) ans += s.substr(0,len) + " ";
        if(ans.size()>0)ans.erase(ans.size()-1,1);
        return ans;
    }
};