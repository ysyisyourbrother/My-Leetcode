#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void print(vector<int> vec)
{
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	return; 
}
void recursion(queue<int> que,stack<int> sta,vector<int> vec)
{
	if(que.empty()&&sta.empty())
	{
		print(vec);
		return;
	}
	else
	{
		if(!que.empty())//动队列 
		{
			//建立临时变量 
			queue<int> temq=que;
			vector<int> temv=vec;
			stack<int> tems=sta; 
			
			int x=temq.front();
			temq.pop();
			
			tems.push(x);//进入栈 
			recursion(temq,tems,vec);
		}
		if(!sta.empty())//动栈
		{
			stack<int> tems=sta;
			vector<int> temv=vec;
			int x=tems.top();
			tems.pop();
			temv.push_back(x);
			recursion(que,tems,temv);
		} 
	}
}
int main()
{
	int N;
	cin >>N;
	queue<int> que;
	vector<int> vec;
	stack<int> sta;
	for(int i=0;i<N;i++)
	{
		int a;
		cin>>a;
		que.push(a);
	}
	recursion(que,sta,vec);
}
