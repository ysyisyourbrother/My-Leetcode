// 牛客网https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github
// 动态规划或递归算法：
        /*
        要覆盖 2*n 的大矩形，可以先覆盖 2*1 的矩形，再覆盖 2*(n-1) 的矩形；
        或者先覆盖 2*2 的矩形，再覆盖 2*(n-2) 的矩形。而覆盖 2*(n-1) 和 2*(n-2) 的矩形可以看成子问题
        
        本质上是一个开始为 1 2 的斐波那契数列
        */
class Solution {
public:
    int rectCover(int number) {
        if(number == 0 ) return 0;
        int a =1;
        int b =2;
        for(int i =2; i<=number;i++)
        {
            int tmp = a+b;
            a = b;
            b = tmp;
        }
        return a;
    }
};