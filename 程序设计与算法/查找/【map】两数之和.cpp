#include "headfile.h"
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) 
{
	vector<int> result;
	map<int,int> m;
	map<int,int>::iterator it;
	for(int i =0;i<nums.size();i++)
	{
		it = m.find(nums[i]);
		if(it!=m.end())
		{
			result.push_back((*it).second);
			result.push_back(i);
			return result;
		}
		m[target-nums[i]]=i;
	}
}
int main()
{
	
}
