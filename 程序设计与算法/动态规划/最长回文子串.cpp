#include "headfile.h"
using namespace std;
string longestPalindrome(string s) {
	if(s == "") return "";
	int arr[1000][1000];
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<s.length();j++)
		{
			arr[i][j]=0;
		}
	}
	//初始化对角线和向右第二条对角线
	int maxi=0;
	int maxj=0;
	for (int i=0;i<s.length();i++)
	{
		arr[i][i]=1;
	}
	for(int i=0;i<s.length()-1;i++)
	{
		int j=i+1;
		if(s[i]==s[j]) 
		{
			arr[i][j]=1;
			maxi=i;
			maxj=j;
		}
	}

	for(int Wid=2;Wid<s.length();Wid++)//一直向右逐条对角线填写
	{
		for(int i=0;i<s.length()-Wid;i++)
		{
			int j=i+Wid;
			if(arr[i+1][j-1]==1&&s[i]==s[j])
			{
				arr[i][j]=1;
				maxi=i;
				maxj=j;
			}	
		}
	}
	return s.substr(maxi,maxj-maxi+1);
}

int main()
{
	string a="babad";
	cout << longestPalindrome(a);
}
