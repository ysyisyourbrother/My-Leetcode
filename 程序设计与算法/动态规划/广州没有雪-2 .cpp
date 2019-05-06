#include <iostream>
using namespace std;
long long matrix[100001][3];//第三列是答案 
int main()
{
	long long day;
	cin>>day;
	long long ptr=0;//指向最后一个0的雪堆位置 
	for(long long i = 0;i<day;i++)
	{
		cin>>matrix[i][0];
	}
	for(long long i=0;i<day;i++)
	{
		cin>>matrix[i][1]; 
	}
	for(long long i =0;i<day;i++)//遍历 
	{
		long long sum=0;
		for(long long j=ptr;j<=i;j++)
		{
			if(matrix[j][0]<=matrix[i][1])
			{
				sum+=matrix[j][0];
				ptr++;
			}
			else
			{
				matrix[j][0]-=matrix[i][1];
				sum+=matrix[i][1];
			}
		 } 
		 matrix[i][2]=sum;
	}
	for(long long i=0;i<day;i++)
	{
		cout<<matrix[i][2];
		if(i!=day-1)
		{
			cout<<" ";
		}
	}
	cout<<endl;
}
