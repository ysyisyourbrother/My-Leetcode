#include "headfile.h"
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        // 快速排序的思想
        if(nums.size()<=1) return nums;
        int left = 0;
        int right = nums.size()-1;
        int pivot = nums[left];
        while(left<right)
        {
            // 如果他是一个奇数 移动到前面来
            while(left<right && nums[right]%2!=1) 
                right--;
            if(left<right)
                nums[left]=nums[right], left++;

            while(left<right && nums[left]%2!=0) // 如果是一个偶数，向后面移动
                left++;
            if(left<right)
                nums[right] = nums[left], right--;
        }
        nums[left]=pivot;
        return nums;
    }
};