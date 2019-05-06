#include <iostream>
#include <algorithm>
using namespace std;
void insertion_sort_interval(int *arr,int start,int increment,int len)
{
	int first_unsorted=start;
	int current,position;
	while((first_unsorted+increment)<len)
	{
		first_unsorted+=increment;
		position=first_unsorted;
		current=arr[first_unsorted];
		while(position>=start+increment&&arr[position-increment]>current)
		{
			swap(arr[position],arr[position-increment]);
			position-=increment;
		}
		arr[position] = current;
	}
}
void shell_sort(int *arr,int len)
{
	int increment,start;
	increment=len;//定义初始的增量为数组长度len 
	do
	{
		increment=increment/3+1;//每次增量变为这个
		for(start=0;start<increment;start++)
		{
			insertion_sort_interval(arr,start,increment,len);
		}
	}while(increment>1);
}
int main()
{
	int a[]={0,2,4,3,10000,1,10,7,4,};
	int len = sizeof(a)/sizeof(int);
	shell_sort(a,len);
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" " ; 
	}
 } 
