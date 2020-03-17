#include "headfile.h"
using namespace std;
class Solution {
public:
    string compressString(string S) {
        if(S.size()==0) return S;
        int count = 0;
        char cur;
        string res;
        for(int i =0;i<S.size();i++)
        {
            if(count == 0) 
            {
                cur = S[i]; // 记录下当前字符
                count++;
            }
            else if(S[i] == cur) // 如果和当前计数的字符相同
            {
                count++;
            }
            else// 如果和当前计数字符不同 结束此次记录开始新的字符
            {
                res+=cur;
                res+=to_string(count);
                count = 0;
                cur = S[i];
            }
        }
        return res.size()<S.size()?res:S;
    }
};