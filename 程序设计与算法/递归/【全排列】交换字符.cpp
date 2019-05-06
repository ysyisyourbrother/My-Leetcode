#include <iostream>
#include <string>
#include <cstring>
/*
	todo:按照输入的字符串中字符出现顺序作为字典序进行全排列 
*/
using namespace std;
void change(char &a,char &b)
{
	char hold;
	hold=a;
	a=b;
	b=hold;
}
void permutation(string data,int begin,int end)
{
	if(begin==end)
	{
		cout<<data<<endl;
		return;
	}
	else
	{
		for(int i=begin;i<=end;i++)
		{
			change(data[begin],data[i]);	
			permutation(data,begin+1,end);
		}
	}	
}
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		string data;
		cin>>data;
		permutation(data,0,data.size()-1);
	}
	return 0;
 } 
