#include "headfile.h"
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() > 1 && p[1] == '*') { // 如果p的下一个字符是*号 分两种情况
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') &&  // 第一种：当前对应字符不同，则p去掉前两个继续匹配
                isMatch(s.substr(1), p));//第二种：当前对应字符相同，s后移动一个，因为p有*，所以不用管
        }
        // 如果p的下一个字符不是*号，考虑s为空的情况，然后判断当前字符是否相同，相同的话各自后移一位继续递归
        return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
};
