#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> x1, pair<string, int> x2)
{
	if (x1.second > x2.second) 
		return 1;
	else if (x1.second == x2.second)
	{
		if (x1.first<x2.first)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
int main()
{
	vector<string> text;
	vector<pair<string,int> > ans;
	string a;
	while(cin>>a)//¶ÁÈ¡ÎÄ±¾ 
	{
		text.push_back(a);
	}
	for(int i=0;i<text.size();i++)
	{
		for(int j=0;j<ans.size();j++)
		{
			if(ans[j].first==text[i])
			{
				ans[j].second++;
				break;
			}
			if(j==ans.size()-1)
				ans.push_back(make_pair(text[i],1));
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans[0].first<<endl;
	
}
