#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int find_biggest(vector<int> t,int low,int high)
{
	int biggest=low;
	for(int i=low+1;i<=high;i++)
	{
		if(t[i]>=t[biggest])
		biggest=i;
	}
	return biggest;
}
int find_smallest(vector<int> t,int low,int high)
{
	int smallest=low;
	for(int i=low+1;i<=high;i++)
	{
		if(t[i]<=t[smallest])
		smallest=i;
	}
	return smallest;
}
int main()
{
	int n,m;
	int temp;
	cin>>n;
	vector<int> arr;
	for(int j=0;j<n;j++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	
	cin>>m;
	while(m--)
	{
		vector<int> t;
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			t.push_back(temp);
		}
		int i;
		for(i=0;i<t.size();i++)
		{
			if(find_biggest(t,0,i)==i&&find_smallest(t,i,t.size()-1)==i)
			{
				cout<<"Yes"<<endl;
				break;
			}
		}
		if(i==t.size())
			cout<<"No"<<endl;
	}
 } 
