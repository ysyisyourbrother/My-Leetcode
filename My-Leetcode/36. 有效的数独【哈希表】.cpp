#include "headfile.h"
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        bool grid[9][9];//定义9个方格
        bool col[9][9];//定义9列
        bool row[9][9];//定义9行
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                grid[i][j]=0;
                col[i][j]=0;
                row[i][j]=0;
            }
        }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int tem;
                if (board[i][j]=='.')
                    continue;
                else
                    tem=board[i][j]-'0'-1;
                int g=i/3+(j/3)*3;
                if(grid[g][tem]==0 && col[i][tem]==0 && row[j][tem]==0)//这里可以放置这个数字
                {
                    grid[g][tem]=1;
                    col[i][tem]=1;
                    row[j][tem]=1;
                }
                else
                {
                    return false;
                }   
            }
        }
        return true;
    }
};