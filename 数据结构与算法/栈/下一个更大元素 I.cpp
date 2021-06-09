#include "headfile.h"
using namespace std;
//加入值！！
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
{
	stack<int> sta;
	map<int,int> m;
	for(int i=0;i<nums.size();i++)
	{
		while(!sta.empty()&&sta.top()<nums[i])
		{
			m[sta.top()]=nums[i];
			sta.pop();
		}
		sta.push(nums[i]);
		m[nums[i]]=-1;
	}
	vector<int> result;
	for(int i=0;i<findNums.size();i++)
	{
		result.push_back(m[findNums[i]]);
	}
	return result;
}
int main()
{
	vector<int> a;
	vector<int> b;
	vector<int> c;
	a.push_back(4);
	a.push_back(1);
	a.push_back(2);
	b.push_back(1);
	b.push_back(3);
	b.push_back(4);
	b.push_back(2);
	c=nextGreaterElement(a,b);
	for(int i=0;i<c.size();i++)
	{
		cout<<c[i]<<endl;
	}
}
