#include "headfile.h"
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int res=0;
        if(g.size()==0||s.size()==0) return 0;
        while(j<s.size()&&i<g.size())
        {
            if(s[j]>=g[i])
            {
                res++;
                j++,i++;
            }
            else
            {
                j++;
            }
        }
        return res;
    }
};