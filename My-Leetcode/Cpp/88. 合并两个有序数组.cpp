#include "headfile.h"
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 定义两个指针，同时向右边移动遍历数组
        int l1 = 0;
        int l2 = 0;
        int cur_size = m; // 记录nums1当前有效数字的长度
        while(l1<cur_size && l2<n)
        {
            if(nums1[l1]<=nums2[l2]) // 如果nums1的小于nums2的，继续
                l1++;
            else
            {
                movestring(nums1,l1, cur_size-1);
                nums1[l1] = nums2[l2];
                l2++;
                l1++;
                cur_size++;
            }
        }
        if(l1>=cur_size)
        {
            // 如果l1到达了m的位置，把nums2剩下的数字补上去
            while(l1<nums1.size())
            {
                nums1[l1] = nums2[l2];
                l1++;
                l2++;
            }
        }
        
    }
    void movestring(vector<int>& nums1, int begin, int end)
    {
        // 将nums1数据元素 从begin位置开始到end位置的数字向右移动一位
        for(int i = end;i>=begin;i--)
        {
            nums1[i+1] = nums1[i];
        }
    }
};