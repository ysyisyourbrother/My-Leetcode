#include "headfile.h"
using namespace std;
/*
    求解方法和全排列几乎一样，就加了一个用map去重复的方法。
*/
class Solution {
public:
    void recursion(vector<vector<int> >&res,vector<int>& nums,int cur=0)
    {
        if(cur==nums.size()-1)//递归到nums的最后一个数字的时候，直接加入res结果并返回
        {
            res.push_back(nums);
            return;
        }
        map<int,bool> mymap;//定义一个map来帮忙去重
        for(int i=cur;i<nums.size();i++)
        {
            //判断这个key是否交换过
            if(mymap.find(nums[i])!=mymap.end())
                continue;
            mymap[nums[i]]=1;//如果没有交换过这个元素就标记并进行交换
            //交换cur和i的值
            int tem=nums[cur];
            nums[cur]=nums[i];
            nums[i]=tem;
            recursion(res,nums,cur+1);
            //回朔，还原交换的值
            tem=nums[cur];
            nums[cur]=nums[i];
            nums[i]=tem;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int> > res;
        if(nums.size()==0) return res;
        recursion(res,nums);
        return res;
    }
};