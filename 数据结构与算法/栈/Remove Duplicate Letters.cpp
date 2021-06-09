#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
string removeDuplicateLetters(string s) 
{
    int alpha[26]={0};
    bool is_use[26]={0};
	stack<char> sta;
    for(int i=0;i<s.size();i++)
    {
    	alpha[s[i]-'a']++;
	}
	for(int i=0;i<s.size();i++)
	{
		if(sta.empty())
		{
			sta.push(s[i]);
			is_use[s[i]-'a']=1;
		}	
		else if(is_use[s[i]-'a']==0)
		{
			is_use[s[i]-'a']=1;
			while(!sta.empty()&&sta.top()>s[i]&&alpha[sta.top()-'a']>0)
			{
				is_use[sta.top()-'a']=0;
				sta.pop();
			}
			sta.push(s[i]);
		}
		alpha[s[i]-'a']--;
	}
	//Êä³ö 
	string temp;
	while(!sta.empty())
	{
		char a=sta.top();
		temp.push_back(a);
		sta.pop();
	}
	reverse(temp.begin(),temp.end());
	return temp;
}
int main()
{
	string a="bcabc";
	cout<<removeDuplicateLetters(a);
}
