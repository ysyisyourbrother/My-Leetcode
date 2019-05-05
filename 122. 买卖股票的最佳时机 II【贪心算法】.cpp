#include "headfile.h"
using namespace std;
class Solution {
public:
    int countProfit(int index,vector<int>& prices,int money,int flag)// 递归暴力搜索
    {
        if(index==prices.size()) return 0;
        if(flag==0)// 当前没有持有股票，可以考虑购买
        {
            int no_buy = countProfit(index+1,prices,0,0);// 不选择购买
            int buy = countProfit(index+1,prices,prices[index],1);//选择购买
            return no_buy>buy?no_buy:buy;
        }
        else if(prices[index]>money)// 如果大于买入价格，可以考虑出售
        {
            int no_sale = countProfit(index+1,prices,money,1);
            int sale = prices[index]-money+countProfit(index+1,prices,0,0);
            return no_sale>sale?no_sale:sale;
        }
        else return countProfit(index+1,prices,money,1);
    }

    // 解法2 使用峰谷的关系来解决，统计所有连续谷->峰的差，leetcode官方提示
    int peak_valley(vector<int>& prices)
    {
        int len = prices.size();
        if(len<2) return 0;
        vector<int> valley=prices;//构建峰和谷 0是谷  1是峰 -1则什么都不是d

        if(prices[0]-prices[1]<0)
            valley[0]=0;
        else valley[0]=1;
        if(prices[len-1]-prices[len-2]<0)
            valley[len-1]=0;
        else valley[len-1]=1;
        for(int i=1;i<prices.size()-1;i++)
        {
            //cout<<prices[i-1]<<" "<<prices[i]<<" "<<prices[i+1]<<endl;
            if(prices[i]-prices[i-1]>0&&prices[i]-prices[i+1]>=0)
                valley[i]=1;
            else if(prices[i]-prices[i-1]<=0&&prices[i]-prices[i+1]<0)
                valley[i]=0;
            else
                valley[i]=-1;
        }
        for(int i=0;i<valley.size();i++)
        {
            cout<<valley[i]<<" ";
        }
        int flag=0;
        int profit=0;
        int v=0;
        for(int i=0;i<prices.size();i++)
        {
            if(flag==0)
            {
                if(valley[i]==0)
                {
                    flag=1;
                    v=prices[i];
                    continue;
                }
            }
            else
            {
                if(valley[i]==1)
                {
                    profit+=prices[i]-v;
                    flag=0;
                    continue;
                }
            }
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        return peak_valley(prices);
    }
};
int main()
{
	
}