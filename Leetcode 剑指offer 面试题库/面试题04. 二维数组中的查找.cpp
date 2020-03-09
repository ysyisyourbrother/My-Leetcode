# include "headfile.h"
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 定义开始位置
        int x = m-1;
        int y = 0;
        while(x>=0 && y<n)
        {
            if(matrix[x][y] == target)
                return true;
            else if(matrix[x][y] < target)
                y+=1;
            else
                x-=1;
        }
        return false;
    }
};