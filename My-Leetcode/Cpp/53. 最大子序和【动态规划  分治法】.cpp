#include "headfile.h"
using namespace std;
class Solution {
public:
    //动态规划 时间复杂度o(n)
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int a[1000];
        int Max = a[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(a[i-1]>0) a[i]=a[i-1]+nums[i];
            else a[i]=nums[i];
            if(a[i]>Max) Max=a[i];
        }
        return Max;
    }
    //分治法 时间复杂度o(nlogn)
    /*思路：将数组分为左右两部分，用递归求解方法分别求最大子序和，再将左右两部分和中间值nums[mid]进行整合,先将nums[mid]和左边部分进行整合，再和右边进行整合，用两个for循环；最终得到左半边最大子序和l，右半边最大子序和r，和num_max，这三个的最大值就是最后的答案。*/
    int maxSubArray2(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return fenzhifa(nums,0,nums.size()-1);
    }
    int fenzhifa(vector<int>& nums,int left,int right)
    {
        if(left>right) return INT_MIN;
        if(left==right) return nums[left];
        int mid=(left+right)/2;
        int l=fenzhifa(nums,0,mid-1);//求左半边最大子序和
        int r=fenzhifa(nums,mid+1,right);//求右半边最大子序和
        
        int t=nums[mid];
        int max_num=nums[mid];

        for(int i=mid-1;i>=left;i--)//整合左半部分
        {
            t+=nums[i];
            max_num=max(max_num,t);
        }
        t=max_num;
        for(int i=mid+1;i<=right;i++)//整合右半部分
        {
            t+=nums[i];
            max_num=max(max_num,t);
        }
        return max(max(r,l),max_num);
    }
}