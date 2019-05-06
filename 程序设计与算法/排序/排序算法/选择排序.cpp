#include <iostream>
#include <algorithm>
using namespace std;
int max_key(int *arr,int low,int high)
{
	int largest;
	largest=low;
	for(int i=low+1;i<=high;i++)
	{
		if(arr[i]>arr[largest])
			largest=i;
	}
	return largest;
}
void selection_sort(int *arr,int len)
{
	for(int position=len-1;position>0;position--)
	{
		int max = max_key(arr,0,position);
		swap(arr[max],arr[position]);
	}
}
int main()
{
	int a[]={3,5,1,2,0,9,4,5,6,10};
	int len=sizeof(a)/sizeof(int);
	selection_sort(a,len);
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	 } 
} 
