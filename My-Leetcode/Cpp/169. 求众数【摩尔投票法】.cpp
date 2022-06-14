#include "headfile.h"
using namespace std;
class Solution {
public:
    /*
    方法一：摩尔投票法
    首先我们注意到这样一个现象： 在任何数组中，出现次数大于该数组长度一半的值只能有一个。
    通过数学知识，我们可以证明它的正确性，但是这并不在我们这篇博客里涉及。
    摩尔投票法的基本思想很简单，在每一轮投票过程中，从数组中找出一对不同的元素，将其从数组中删除。这样不断的删除直到无法再进行投票，如果数组为空，则没有任何元素出现的次数超过该数组长度的一半。如果只存在一种元素，那么这个元素则可能为目标元素。
    那么有没有可能出现最后有两种或两种以上元素呢？根据定义，这是不可能的，因为如果出现这种情况，则代表我们可以继续一轮投票。因此，最终只能是剩下零个或一个元素。
    在算法执行过程中，我们使用常量空间实时记录一个候选元素c以及其出现次数f(c)，c即为当前阶段出现次数超过半数的元素。根据这样的定义，我们也可以将摩尔投票法看作是一种动态规划算法。 
    初始化的情况下计数器为0.
    算法依次扫描序列中的元素，当处理元素x的时候，如果计数器为0，那么将x赋值给value，然后将计数器count设置为1，如果计数器不为0，那么将序列元素value和x比较，如果相等，那么计数器加1，如果不等，那么计数器减1。
    最后存储的序列元素(value)，就是这个序列中最多的元素。
    */
    int majorityElement1(vector<int>& nums) {
        int count = 0;
        int value = 0;
        for(auto& x:nums) {
            if(count == 0){
                value = x;
                count = 1;
            } else if(value == x){
                count++;
            } else {
               count--;
            }
        }
        return value;
    }
    // 方法二：使用map来计算每个数字出现的次数
    int majorityElement2(vector<int>& nums) {
        map<int,int> mymap;
        int n=nums.size();
        n = ceil(n/2.0);
        map<int,int>::iterator it;
        for(int i=0;i<nums.size();i++)
        {
            it=mymap.find(nums[i]);
            if(it!=mymap.end())
                mymap[nums[i]]++;
            else
                mymap[nums[i]]=1;
            if(mymap[nums[i]]>=n)
                return nums[i];
        }
        return -1;
    }
};