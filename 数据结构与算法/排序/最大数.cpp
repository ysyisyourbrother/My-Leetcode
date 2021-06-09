#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
//#include "headfile.h"
using namespace std;
bool cmp(int a, int b)
{
	string x = std::to_string(a);
	string y = std::to_string(b);
	return x+y>y+x;
}
std::string largestNumber(vector<int>& nums)
{
	sort(nums.begin(), nums.end(), cmp);
	/*for (int i = 0; i<nums.size(); i++)
	{
		cout << nums[i] << " ";
	}*/
	std::string res;
	for (int i = 0; i<nums.size(); i++)
	{
		res += std::to_string(nums[i]);
	}
	int i;
	for (i = 0; i<res.size(); i++)
	{
		if (res[i] != '0')
		{
			break;
		}
	}
	if (i == res.size()) return "0";
	return res.substr(i);
	return res;
}

int main()
{
	vector<int> a;
	a.push_back(5);
	a.push_back(88);
	a.push_back(78);
	a.push_back(88);
	a.push_back(35);
	a.push_back(35);
	a.push_back(21);
	cout<<largestNumber(a);
	
}
