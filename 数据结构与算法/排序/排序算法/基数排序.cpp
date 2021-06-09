#include <iostream>
#include <algorithm>
using namespace std; 
int GetMaxDigit(int* arr, int n)
{
	int digit = 1;
	int base = 10;
	for (int i = 0; i < n; i++)//统计n个数中最大数的位数 
	{
		while (arr[i] >= base)
		{	
			++digit;
			base *= 10;
		}
	}
	return digit;
}
void LSDSort(int* arr,int n)//从低位向高位排 
{ 
	int base = 1;
	int digit = GetMaxDigit(arr, n);
	int *tmp = new int[n]; 
	while (digit--)//每一位都要执行一次排序 
	{
		int count[10] = { 0 };
		//统计某一位出现相同数字的个数
		for (int i = 0; i < 10; i++)
		{
			int index = arr[i] / base % 10;
			count[index]++;
		}
		int start[10] = { 0 };//start[0]一定为0因为0一定是从第一个位置开始 
		//统计个位相同的数在数组arr中出现的位置
		for (int i = 1; i < 10; i++)
		{
			start[i] = count[i - 1] + start[i - 1];
		}
		//从桶中重新排序数据
		for (int i = 0; i < n; ++i)
		{
			int index = arr[i] / base % 10;
			tmp[start[index]++] = arr[i];
		}
		//将tmp数组中的元素拷回原数组
		memcpy(arr, tmp, n*sizeof(int));
		base *= 10;
	}
	delete[] tmp;
}
void Print(int* arr, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[10] = { 123, 234, 543, 324, 568, 975, 547, 672, 783, 239 };
	LSDSort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
 } 

