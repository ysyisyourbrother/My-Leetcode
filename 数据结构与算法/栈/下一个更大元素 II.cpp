#include "headfile.h"
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) 
{
	stack<int> sta;//第一个是在extG数组中的下标，第二个是对应位置的值的值
	int nextG[10005]={0};
	for(int i=0;i<nums.size();i++)
		nextG[i]=-1;
	for(int i=0;i<2*nums.size();i++)
	{
		while(!sta.empty()&&nums[sta.top()]<nums[i%nums.size()])
		{
			nextG[sta.top()]=nums[i%nums.size()];
			sta.pop();
		}
		sta.push(i%nums.size());
	}
	vector<int> result;
	for(int i=0;i<nums.size();i++)
	{
		result.push_back(nextG[i]);
	}
	return result;
}
int main()
{
	vector<int> a;
	vector<int> b;
	vector<int> c;
	b.push_back(1);
	b.push_back(2);
	b.push_back(1);
	c=nextGreaterElements(b);
	for(int i=0;i<c.size();i++)
	{
		cout<<c[i]<<endl;
	}
}
