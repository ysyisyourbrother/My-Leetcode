#include <iostream>
#include <cmath>
using namespace std;
#define left(x) 2*x+1
#define right(x) 2*x+2//因为数组下标是从0开始的，所以对应每个非树叶节点x,他的左右节点分别为2x+1 2x+2
void MaxHeap(int *a,int i,int high)//更新某个节点满足最大堆 
//a为要排序数组，i为要排序的节点，high为数组要被维护的最大下标 
{
	int l=left(i);
	int r= right(i);
	int largest;//三者较大节点下标 
	int temp;
	//找出r l 和 i位置的节点值的最大值 并和i位置交换 
	if(l<=high && a[l]>a[i])
		largest=l; 
	else  
		largest = i;
	if(r<=high&&a[r]>a[largest])
		largest=r;
	if(largest!=i)//当 最大的值是在位置 i 或者 l和r都不存在时 largest=i,此时不交换，函数返回。 
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		MaxHeap(a,largest,high);
	}
	
 } 
void buildMaxHeap(int *a,int length)//将数组建立成一个最大堆 
{
 	for(int i=length/2-1;i>=0;i--)
	{
		MaxHeap(a,i,length-1);
	} 
}
void HeapSort(int *a,int length)
{
	int temp;
	buildMaxHeap(a,length);
	for(int i=length-1;i>=1;i--)
	{
		// for(int i=0;i<5;i++)
		// {
		// 	cout<<a[i]<<" ";
		// }
		// cout<<endl;
		temp=a[i];//和数组最后一个元素交换位置	 
		a[i]=a[0];
		a[0]=temp;
		MaxHeap(a,0,i-1);
	}
}
int main()
{
	int a[]={4,6,8,5,9}; 
	HeapSort(a,5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<endl;
	}
 } 
