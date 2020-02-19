#include "headfile.h"
using namespace std;
/*
######求解全排列的方法#######

###交换法###
1、首先看最后两个数4, 5。 它们的全排列为4 5和5 4, 即以4开头的5的全排列和以5开头的4的全排列。
由于一个数的全排列就是其本身，从而得到以上结果。
2、再看后三个数3, 4, 5。它们的全排列为3 4 5、3 5 4、 4 3 5、 4 5 3、 5 3 4、 5 4 3 六组数。
即以3开头的和4,5的全排列的组合、以4开头的和3,5的全排列的组合和以5开头的和3,4的全排列的组合.
于是根据上面的说法，就可以明白为什么可以用交换实现！

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
        for(int i=cur;i<nums.size();i++)
        {
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
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int> > res;
        if(nums.size()==0) return res;
        recursion(res,nums);
        return res;
    }
};