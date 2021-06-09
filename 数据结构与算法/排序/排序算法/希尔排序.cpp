#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<=1) return nums; //如果数组的大小小于等于1 直接返回
        // 希尔排序
        int jump = nums.size()/2; // 定义排序增量间隔
        while(jump) // jump每次变为原来的一半 变为0的时候结束
        {
            for(int i = 0;i<jump;i++)
            {
                // 对每一组进行插入排序
                insert_sort(nums, i , jump);
            }
            jump/=2;
        }
        return nums;
    }
    void insert_sort(vector<int> & nums, int cur, int jump)
    {
        // 有增量的直接插入排序
        while(cur<nums.size())
        {
            int tmp = nums[cur];
            int x = cur - jump;
            while(x>=0 && nums[x]>tmp)
            {
                nums[x+jump] = nums[x];
                x-=jump; 
            }
            nums[x+jump] = tmp;
            cur+= jump;
        }
    }
};

int main()
{
    vector<int> q = {5,2,3,1};
    Solution test;
    test.sortArray(q);
    for(auto i:q)
        cout<<i<<" ";
}