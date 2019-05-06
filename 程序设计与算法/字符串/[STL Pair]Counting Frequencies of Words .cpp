#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp(pair<string,int> x1,pair<string,int> x2)
{
	if(x1.second>x2.second) return 1;
	else if(x1.second==x2.second)
	{
		if(x1.first < x2.first)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
vector<pair<string, int> > frequencies(const vector<string> text, vector<string> keys)
{
	vector<pair<string,int> > ans;
	for(int i=0;i<keys.size();i++)
	{
		ans.push_back(make_pair(keys[i],0));
	}
	for(int i=0;i<text.size();i++)
	{
		for(int j=0;j<ans.size();j++)
		{
			if(text[i]==ans[j].first)
			{
				ans[j].second++;
			}
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	vector<pair<string, int> >::iterator it=ans.begin();
	for(;it!=ans.end();it++)
	{
		if((*it).second==0)
			break;
	}
	for(;it!=ans.end();)
	{
		it = ans.erase(it);
	}
	return ans;
}
int main()
{
	vector<string> text;
	vector<string> keys;
	
	text.push_back("algorithm");
	text.push_back("range");
	text.push_back("time");
	text.push_back("algorithm");
	text.push_back("Algorithm");
	text.push_back("that");
	text.push_back("is");
	text.push_back("time");
	
	keys.push_back("range");
	keys.push_back("algorithm");
	keys.push_back("time");
	keys.push_back("complexity");
	vector<pair<string, int> > ans = frequencies(text,keys);
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i].second!=0)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
}
