#include "headfile.h"
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        map<string,int> m1; //储存容器中的字符串便于查找是否存在
        map<string,int> re; //储存路径长度的结果，beginword为1
        int n = wordList.size();
        for(int i = 0; i < n; i ++)
            m1[wordList[i]] = 1;
        re[beginWord] = 1;
        q.push(beginWord);
        while ((!q.empty()) && m1.size())
        {
            string now = q.front();
            q.pop();
            int num = re[now];
            int llen = now.size();
            for (int i = 0; i < llen; i ++)
            {
                string temp = now;
                for(char c = 'a' ; c <= 'z'; c ++)//当单词表很大的时候，遍历26个字母可能比遍历列表要快
                {
                    if(temp[i] == c)
                        continue;
                    else 
                        temp[i] = c;
                    if(m1.find(temp) != m1.end())
                    {
                      if(temp == endWord)
                        return num + 1;
                      q.push(temp);
                      re[temp] = num + 1;
                      m1.erase(temp);//删除这个单词防止又回到这个单词上遍历
                    }
                }
            }
        }
        return 0;
    }
};
