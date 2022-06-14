#include "headfile.h"
using namespace std;
class Solution {
public:
    bool recursion(vector<vector<char>>& board,bool grid[][9],bool col[][9],bool row[][9],int i,int j)
    {
        if(board[i][j]=='.')
        {
            int g=i/3+(j/3)*3;
            for(int n = 0;n<9;n++)
            {
                if(grid[g][n]==0&&col[i][n]==0&&row[j][n]==0)//回溯法
                {
                    //如果这里可以放置这个数，就修改board和约束数组并递归
                    grid[g][n]=1;
                    col[i][n]=1;
                    row[j][n]=1;
                    board[i][j]=n+'0'+1;
                    if(i==8&&j==8)
                        return true;
                    else if(recursion(board,grid,col,row,i+(j+1)/9,(j+1)%9))//递归下一个位置
                        return true;
                    //如果这个方法不行的话就要恢复原来board的值并返回
                    grid[g][n]=0;
                    col[i][n]=0;
                    row[j][n]=0;
                    board[i][j]='.';
                }
            }
        }
        else
        {
            if(i==8&&j==8)
                return true;
            else if(recursion(board,grid,col,row,i+(j+1)/9,(j+1)%9))//递归下一个位置
                return true;
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        bool grid[9][9];//定义9个方格
        bool col[9][9];//定义9列
        bool row[9][9];//定义9行
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
            {
                grid[i][j]=0;
                col[i][j]=0;
                row[i][j]=0;
            }
        }
        for(int i=0;i<9;i++)//建立初始的数独表
        {
            for(int j=0;j<9;j++)
            {
                if (board[i][j]=='.')
                    continue;
                int tem=board[i][j]-'0'-1 , g=i/3+(j/3)*3;
                grid[g][tem]=1;
                col[i][tem]=1;
                row[j][tem]=1;
            }
        }
        recursion(board,grid,col,row,0,0);//使用回溯法地柜求解问题
    }
};