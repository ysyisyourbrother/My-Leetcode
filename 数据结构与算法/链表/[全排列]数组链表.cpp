#include <iostream>
#define max_degree 10
using namespace std;
void print(int* permutation)
{
	int current=permutation[0];
	while(current!=0)
	{
		cout<<current;
		current=permutation[current];
	}	
	cout<<endl;
	return;
} 
void permute(int n,int degree,int*permutation)
{
	if(n==degree+1)
	{
		print(permutation);//打印全排列
		return; 
	} 
	if(permutation[0]==0)
	{
		permutation[0]=n;//若排列数组中没有元素令头结点的下标为 n作为头
		permute(n+1,degree,permutation); 
	}
	else
	{
		int current = 0;//当前数组链表下标 0下标一定为第一个 
		for(int i=0;i<n;i++)
		{
			//插入一个元素进入链表 ： 
			permutation[n]=permutation[current];
			permutation[current]=n;
			//递归： 
			permute(n+1,degree,permutation);
			//恢复插入前状态，下一个循环插入下一个位置： 
			permutation[current]=permutation[n];
			permutation[n]=0;
			//current进入下一个位置： 
			current=permutation[current]; 
		}
	}
	return;
}
int main()
{
	int degree;//要排到1到degree的全排列
	int permutation[max_degree+1]={0};
	cin>>degree;
	permutation[0]=0;
	permute(1,degree,permutation);
	return 0;
}
