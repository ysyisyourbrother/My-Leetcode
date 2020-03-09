#include "headfile.h"
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int conbo = 0; // 定义连续牌数量
        int array[14]={0};// 定义一个数组 第0位统计king的数量
        // 遍历统计
        for(auto i :nums)
        {       
            if(i==0) // 如果是王
                array[0]++;
            else
                array[i] = 1;
        }
        // 遍历array判断是否连续5个牌
        int flag = 0; // 标记是否开始顺子
        for(int i =1;i<=13;i++)
        {
            if(!flag)
            {
                if(array[i]!=0)// 如果有这个牌，开始conbo
                {
                    conbo++;
                    flag++;    
                }  
                continue;
            }

            // 如果flag为1
            if(array[i]!=0)
                conbo++;
            else if(array[i]==0) //如果没这个牌，就要拿王补
            {
                if(array[0]>0)
                {
                    array[0]--;
                    conbo++;
                    continue;
                }
                else
                    break; // 如果没有王补了，就结束 统计conbo数量
            }
        }
        if(conbo+array[0]>=5)
            return true;
        else
            return false;
    }
};