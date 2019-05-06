#include "headfile.h"
using namespace std;
int lengthOfLongestSubstring(string s) 
{
    if(s.size()==0) return 0;
    int find[256];//装所有的ascII码
    for(int i=0;i<256;i++)
    {
        find[i]=-1;
    }
    int result=0;
    int currentlen=0;
    int begin=0;
    for(int i=0;i<s.size();i++)
    {
        char temp=s[i];
        temp = int(temp);
        if(find[temp]==-1)
        {
            currentlen++;
            find[temp]=i;//记录这个字符所在的位置为i 
        }
        else
        {
            result=currentlen>result?currentlen:result;
            currentlen=i-find[temp];
            //现在要把重复元素前面的元素find都恢复成-1
            for(int j=begin;j<find[temp];j++)
            {
                find[s[j]]=-1;
            }
            begin=find[temp]+1;
            find[temp]=i;
        }
    }
    result=currentlen>result?currentlen:result;
    return result;
}
int main()
{
    string a="  ";
    cout<<lengthOfLongestSubstring(a)<<endl;
}