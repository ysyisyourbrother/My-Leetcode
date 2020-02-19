#include "headfile.h"
using namespace std;
/*
假设严格递增的序列是增序列，非严格递增（递减或者相等）的序列是减序列，则题目给定的序列必定又增减序列交替组成的
从左往右数组，对每个增子序列，都从1开始递增，但此时对减子序列就无效，因为有可能是这样的序列1 2 3 2 1 0，
但每个小朋友又必须至少1个糖果最后一个小朋友不符合，则糖果数量就要改成 1 2 4 3 2 1 可知从左往右只能确定递增序列的结果。
因此我们同理从右边向左边再遍历一次，这样可以确定递减序列，让每一个递减子序列从最后一个元素从1开始反向递增。
最后我们把两个列表和并，取最大的值即可。
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),sum=0;
        vector<int> left(n,1),right(n,1); // 定义数组都初始化为1
        for(int i=1;i<n;i++){ 
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                right[i]=right[i+1]+1;
            sum+=max(left[i],right[i]);
        }
        sum+=max(right[n-1],left[n-1]);
        return sum;
    }
};
int main()
{

}