#include "headfile.h"
// 头文件
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) 
	{
		if(nums.size()==0) return true;
		int cur_far=0; //目前能到达最远的位置
		int index=0;//目前探测到的位置
		for(;index<=cur_far&&cur_far<nums.size()-1;index++)
		{
			if(index+nums[index]>cur_far)
				cur_far=index+nums[index];
		}
		if(cur_far>=nums.size()-1)
		{
			return true;
		}
		return false;
    }
};
int main()
{
	Solution test;
}