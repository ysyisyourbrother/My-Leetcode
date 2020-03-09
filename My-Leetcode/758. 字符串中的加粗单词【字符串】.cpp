#include "headfile.h"
using namespace std;
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string res;
        if(S.size()==0) return res;
        vector<int> judge(S.size(),0);
        for(auto word : words)
        {
            int index = 0;
            while(index<S.length() && (index = S.find(word, index))!= S.npos) // 如果还找到子串 或者index已经超过长度了
            {
                // 将judge对应的位置填上1代表要加粗
                for(int i =0;i<word.size();i++)
                {
                    judge[index+i]=1;
                }
                index++; // index往后移动一位
            }
        }
        for(auto i :judge)
        {
            cout<<i<<" ";
        }
        // 根据judge对字符串进行加粗
        for(int i=0;i<S.size();i++)
        {
            if(judge[i]==0)// 如果为0 判断前一位  注意第一个字符情况
            {
                if(i!=0 && judge[i-1]==1) //如果前一位为1 </b>
                    res+="</b>";
                res += S[i];
            }
            else//如果为1，判断前一位
            {
                if(i==0 || judge[i-1]==0) //如果前一位为0，则加粗
                    res+="<b>";
                res+=S[i];
            }
        }   
        // 单独考虑最后一个字符
        if(judge[S.size()-1]==1)
            res+="</b>";
        return res;
    }
};