#include "headfile.h"
using namespace std;
/*
1.s1[i-1] == s2[j-1]，新增的两个字符相等的情况下，没有必要删除之前的结果，因此dp[i][j] = dp[i-1][j-1]
2.s1[i-1] != s2[j-1]，取三者的最小值
（1）保留s2串，删除s1串的字符，dp[i][j] = dp[i-1][j] + s1.charAt(i-1)
（2）保留s1串，删除s2串的字符，dp[i][j] = dp[i][j-1] + s1.charAt(j-1)
（3）删除s1、s2串的字符，dp[i][j] = dp[i-1][j-1] + s1.charAt(i-1) + s2.charAt(j-1)
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int matrix[1005][1005];//定义一个二维数组来dp 0行和0列表示空串
        //初始化dp矩阵第一行和第一列
        matrix[0][0]=0;
        for(int i=1;i<=s2.size();i++)
            matrix[0][i]=matrix[0][i-1]+s2[i-1];
        for(int i=1;i<=s1.size();i++)
            matrix[i][0]=matrix[i-1][0]+s1[i-1];
        //开始dp
        for(int i=1;i<=s1.size();i++)
            for(int j=1;j<=s2.size();j++)
                if(s1[i-1]!=s2[j-1])
                    matrix[i][j]=min(matrix[i-1][j]+s1[i-1],min(matrix[i-1][j-1]+s1[i-1]+s2[j-1],matrix[i][j-1]+s2[j-1]));
                else
                    matrix[i][j]=matrix[i-1][j-1];
        return matrix[s1.size()][s2.size()];
    }
};