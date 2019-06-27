#include "headfile.h"
using namespace std;
/*
    二分查找法，从左下角或者右上角开始查找，根据大小决定行数向上（下）移动或者列数向右（左）移动
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int x = matrix.size() - 1, y = 0;
        while (true) {
            if (matrix[x][y] > target) --x;
            else if (matrix[x][y] < target) ++y;
            else return true;
            if (x < 0 || y >= matrix[0].size()) break;
        }
        return false;
    }
};
int main()
{

}