#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int N,M;//一共N只猴子数组下标1到N 
		cin>>N>>M;
		int array[10005];
		for(int i=1;i<N;i++)
		{
			array[i]=i+1;
		}
		array[N]=1;	
		int count=N;
		int number=1;//当前下标号 
		if(M==1)
		{
			cout<<N<<endl;
			continue;
		} 	
		while(count>1)
		{
			for(int i=0;i<M-2;i++)//获取要被删除的猴子编号 前一个 
			{
				number=array[number];
			}
			array[number] = array[array[number]];//删除节点 
			count--;
			number = array[number];//指针后移 
		}	
		cout<<number<<endl;
	}
 } 
