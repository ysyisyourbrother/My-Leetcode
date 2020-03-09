// 本质还是一个斐波那契数列的问题
class Solution {
public:
    int numWays(int number) {
        if(number == 0 ) return 1;
        int a =1;
        int b =2;
        for(int i =2; i<=number;i++)
        {
            int tmp = (a+b)%int(1e9+7);
            a = b;
            b = tmp;
        }
        return a;
    }
};