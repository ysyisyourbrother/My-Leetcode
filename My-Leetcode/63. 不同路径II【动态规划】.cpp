#include "headfile.h"
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int hei=obstacleGrid.size();
        int wid=obstacleGrid[0].size();
        if(hei==0||wid==0) return 0;//图是空的

        long long matrix[150][150];
        if (obstacleGrid[0][0]==0)//第一个点就无路可走
        {
            matrix[0][0]=1;
        }
        else return 0;
        for(int i=1;i<wid;i++)
            matrix[0][i]=(obstacleGrid[0][i]==0?matrix[0][i-1]:0);
        for(int i=1;i<hei;i++)
            matrix[i][0]=(obstacleGrid[i][0]==0?matrix[i-1][0]:0);
        for(int i=1;i<hei;i++)
        {
            for(int j=1;j<wid;j++)
            {
                matrix[i][j]=(obstacleGrid[i][j]==0?matrix[i][j-1]+matrix[i-1][j]:0);
            }
        }
        return matrix[hei-1][wid-1];
    }
};
int main()
{

}