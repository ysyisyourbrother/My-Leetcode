#include <iostream>
#include <algorithm>
using namespace std;
void QuickSort1(int s[], int l, int r) //返回调整后要进行快速排序的数组下标范围 
{
	if(l>=r)//当要调整的数组长度小于等于1的时候返回 
		return;
    int i = l, j = r;
    int x = s[l]; //s[l]即s[i]就是第一个坑
    while (i < j)
    {
        // 从右向左找小于x的数来填s[i]
       while(i < j && s[j] >= x)
            j--;
        if(i < j)
        {
            s[i] = s[j]; //将s[j]填到s[i]中，s[j]就形成了一个新的坑
            i++;
        }
        // 从左向右找大于或等于x的数来填s[j]
        while(i < j && s[i] < x)
            i++;
        if(i < j)
        {
            s[j] = s[i]; //将s[i]填到s[j]中，s[i]就形成了一个新的坑
            j--;
        }
    }
    //退出时，i等于j。将x填到这个坑中。
    s[i] = x;
    QuickSort1(s, l, i - 1); // 递归调用，不用包含pivot
	QuickSort1(s, i + 1, r);	
}

void QuickSort2(int s[],int l,int r)//课本上的快速排序法
{
	if(l>=r)
		return;
	swap(s[l],s[(l+r)/2]);//将数组中间部分的元素换到开头来作为pivot,大概率让数组分成大小接近的两段 
	int pivot=s[l]; //选取第一个元素为支点 
	int first_less=l;
	for(int i=l+1;i<=r;i++)
	{
		if(s[i]<pivot)
		{
			swap(s[i],s[++first_less]);
		}
	}
	swap(s[first_less],s[l]);//将pivot和最后一个严格小于它的值换位，这样左边小于它，右边大于等于它
	QuickSort2(s,l,first_less-1);
	QuickSort2(s,first_less+1,r);
}

int main()
{
	int s[]= {43,16,27,59,50,26,31,48,62,36,13,50,15,27,15,37,37,16,37,21,22,19,41,27,8,25,65,59,60,1,51,18,52,57,65,3,39,51,44,49,59,34,8,64,38,60,45,48,42};
	QuickSort2(s,0,sizeof(s)/sizeof(int)-1);
	for(int i=0;i<sizeof(s)/sizeof(int);i++)
	{
		cout<<s[i]<<" ";
	}
 } 
