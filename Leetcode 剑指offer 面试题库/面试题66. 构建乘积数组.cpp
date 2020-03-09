#include "headfile.h"
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res;
        if(a.size()==0) return res;
        // 因为不允许使用除法，所以构建两个备忘录数组记录乘积
        vector<int> times1(a.size()+1,1);
        vector<int> times2(a.size()+1,1);
        // 构建从左到右的乘积数组
        for(int i =1;i<times1.size();i++)
        {
            times1[i] = times1[i-1]*a[i];
        }
        // 从右向左构建乘积数组
        for(int i =times2.size()-2;i>=0;i--)
        {
            times2[i] = times2[i+1]*a[i];
        }
        // 综合两个数组得出结果
        for(int i = 1;i<times1.size();i++)
        {
            res.push_back(times1[i-1]*times2[i]);
        }
        return res;
    }
};