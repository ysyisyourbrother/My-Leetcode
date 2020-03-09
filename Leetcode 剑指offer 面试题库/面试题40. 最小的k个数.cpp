#include "headfile.h"
using namespace std;
class Solution {
public:
    // 使用堆排序的方法
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if(arr.size()==0) return res;
        int length = arr.size()-1;
        buildMaxHeap(arr,length); // 先构建小顶堆

        //  使用小顶堆选出前k个元素
        while(k--)
        {
            res.push_back(arr[0]);
            swap(arr[0], arr[length]); // 和最后一个位置的数字交换
            // 重新构建小顶堆
            MaxHeap(arr, 0, --length);
        }
        return res;
    }

    void MaxHeap(vector<int>& a,int i,int high)//更新某个节点满足最大堆 
    //a为要排序数组，i为要排序的节点，high为数组要被维护的最大下标 
    {
        int l = 2*i+1;
        int r = 2*i+2;
        int largest;//三者较大节点下标 
        int temp;
        //找出r l 和 i位置的节点值的最大值 并和i位置交换 
        if(l<=high && a[l]<a[i])
            largest=l; 
        else  
            largest = i;
        if(r<=high&&a[r]<a[largest])
            largest=r;
        if(largest!=i)//当 最大的值是在位置 i 或者 l和r都不存在时 largest=i,此时不交换，函数返回。 
        {
            temp=a[i];
            a[i]=a[largest];
            a[largest]=temp;
            MaxHeap(a,largest,high);
        }
        
    } 
    void buildMaxHeap(vector<int>& a,int length)//将数组建立成一个最大堆 
    {
        for(int i=length/2-1;i>=0;i--)
        {
            MaxHeap(a,i,length-1);
        } 
    }
};