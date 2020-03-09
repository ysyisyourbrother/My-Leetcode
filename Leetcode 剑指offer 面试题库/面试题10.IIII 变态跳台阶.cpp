// 本质还是一个斐波那契数列的问题
// 会发现是一个等比数列，直接用pow计算即可
// 牛客网https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github
class Solution {
public:
    int jumpFloorII(int number) {
        return pow(2,number-1);
    }
};