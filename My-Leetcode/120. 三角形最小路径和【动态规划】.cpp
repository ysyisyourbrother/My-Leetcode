#include "headfile.h"
using namespace std;
class Solution {
public:
    /*
    方法1：正向推导，使用O(n)的数组正向迭代
    */
    int minimumTotal(vector<vector<int>>& triangle) {
        int *arr=new int[triangle.size()+1];//声明空间
        int teml=0,temu=0;//保存会被覆盖的值
        if(triangle.size()==0) return 0;
        else arr[0]=triangle[0][0];//如果triangle不是空的，先把第一行第一个数加入的数组
        for(int row=1;row<triangle.size();row++)
        {
            for(int col=0;col < row+1;col++)
            {
                teml=temu, temu=arr[col];//迭代更新
                if(col==0)//如果是第一列 直接更新不用比较
                    arr[col]=arr[0]+triangle[row][col];
                else if(col==row)//如果是最后一列 直接更新不用比较
                    arr[col]=teml+triangle[row][col];
                else//中间部分的值 比较取小的更新
                    arr[col]=teml<temu?(teml+triangle[row][col]):(temu+triangle[row][col]);
            }
        }
        int min=INT_MAX;
        for(int i=0;i<triangle.size();i++)
            if(arr[i]<min)
                min=arr[i];
        delete []arr;
        return min;
    }
    /*
    方法2：反向推导，不需要额外的空间，直接使用题目给的triangle的空间反向迭代！ 太精彩了！！
    */
    int minimumTotal2(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 0)
            return 0;

        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j < triangle[i].size(); j++)
                triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];

        return triangle[0][0];
    }
};