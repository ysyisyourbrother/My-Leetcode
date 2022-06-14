#include "headfile.h"
using namespace std;
class Solution {
public:
    bool rightpos(int x,int y,vector<vector<char>>& board)
    {
        if(x>=0&&x<board.size()&&y>=0&&y<board[0].size())
            return true;
        return false;
    }
    bool recursion(vector<vector<char>>& board, string word, int cur,int x,int y)
    {
        if(cur==word.size()) return true;
        char aim=word[cur];
        bool res=false;
        char tem=board[x][y];
        board[x][y]='*';
        if((!res)&&rightpos(x,y-1,board)&&board[x][y-1]==aim)
            res=recursion(board,word,cur+1,x,y-1);
        if((!res)&&rightpos(x,y+1,board)&&board[x][y+1]==aim)
            res=recursion(board,word,cur+1,x,y+1);
        if((!res)&&rightpos(x-1,y,board)&&board[x-1][y]==aim)
            res=recursion(board,word,cur+1,x-1,y);
        if((!res)&&rightpos(x+1,y,board)&&board[x+1][y]==aim)
            res=recursion(board,word,cur+1,x+1,y);
        board[x][y]=tem;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return true;
        if(board.size()==0||board[0].size()==0) return false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(recursion(board,word,1,i,j)) 
                        return true;
                }
                    
            }
        }
        return false;
        
    }
};