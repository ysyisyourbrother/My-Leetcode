#include "headfile.h"
using namespace std;
class Solution {
public:
	// 桶排序方法
    int missingNumber1(vector<int>& nums) {
		vector<int> res(nums.size()+1, 0);
		for(int i =0;i<nums.size();i++)
			res[nums[i]] = 1;
		for(int i =0;i<res.size();i++)
			if(res[i] == 0)
				return i;
        return -1;
    }
	// 二分查找法，如果当前下标和对应的数一样，说明左边排序都正常，搜右边
	int missingNumber(vector<int>& nums)
	{
		if(nums.size()==0) return 0;
		return bSearch(nums, 0, nums.size()-1);
	}
	int bSearch(vector<int>& nums, int left, int right){
		if(left == right)
		{
			if(nums[left] == left)
				return left+1;
			else
				return left;			
		}
		int mid = (left+right)/2; // 获取中间位置下标 向下去整
		if(nums[mid] == mid) // 如果 对应位置正确， 向右边搜索 反之向左边搜索
			return bSearch(nums,mid+1,right);
		else
			return bSearch(nums,left,mid);	
	}
};