#include "headfile.h"
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) 
	{
		int res;
		int time[100000];
		for(int i=0;i<nums.size();i++)
		{
			time[i]=0;
		}
		int index=0;
		int cur_far=0;
		for(;index<nums.size()-1;index++)
		{
			if(index+nums[index]>cur_far)
			{
				if(index+nums[index]>=nums.size()-1) return time[index]+1;
				int i =cur_far+1;
				cur_far=index+nums[index];
				for(;i<=cur_far;i++)
				{
					time[i]=time[index]+1;
				}
			}
		}
		return time[nums.size()-1];
    }
};
int main()
{
	Solution test;
}