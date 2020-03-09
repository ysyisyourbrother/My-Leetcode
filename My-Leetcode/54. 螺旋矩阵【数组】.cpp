#include "headfile.h"
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0||matrix[0].size()==0) return res;
        vector<vector<int> > judge(matrix.size(),vector<int>(matrix[0].size(),0)); // 定义一个判断的矩阵。

        int x= 0,y=0;// 定义起始位置
        res.push_back(matrix[x][y]);
        judge[0][0] =1;
        int flag = 1;
        while(flag)
        {
            flag = 0; //如果都没得走，结束循环
            // 先向右走
            while(is_legal(x,y+1,judge))
                y++,res.push_back(matrix[x][y]),flag=1,judge[x][y]=1;

            // 向下走
            while(is_legal(x+1,y,judge))
                x++,res.push_back(matrix[x][y]),flag=1,judge[x][y]=1;

            //向左走
            while(is_legal(x,y-1,judge))
                y--,res.push_back(matrix[x][y]),flag=1,judge[x][y]=1;

            while(is_legal(x-1,y,judge))
                x--,res.push_back(matrix[x][y]),flag=1,judge[x][y]=1;
        }
        return res;
    }
    bool is_legal(int x,int y, vector<vector<int> >& judge)
    {
        int limit_x = judge.size();
        int limit_y = judge[0].size();
        if(x>=0 && x<limit_x && y>=0 && y<limit_y &&judge[x][y]==0)
            return true;
        return false;
    }
};