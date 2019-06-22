#include "headfile.h"
using namespace std;
/*
    Bellman-ford算法
    需要增加一个控制每一轮循环最多只能增加一次转机次数，就是不同边做了松弛之后，先不改变原来的数组，而是保存起来在c中，这一轮松弛结束之后在统一赋值给cost，这样就可以保证每次只增加了一次转机次数，就是求出到某一个的路径长度但是不把它更新进去cost中。
    bellman算法保证了第k轮松弛的时候，保证能找到从原点开始的k长度内到某个点的所有路径中的 最短路径
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>cost(n,1e6);cost[src]=0;///将所有权值设为inf，考虑到取值范围为[1, 10000].设为1e6即可。
        for(int i=0;i<=k;i++){
            vector<int>c(cost);//控制每次大循环最多只会增加一次转机次数
            for(auto&e:flights)
                c[e[1]]=min(c[e[1]],cost[e[0]]+e[2]);//松弛
            cost=c;
        }
        return cost[dst]==1e6?-1:cost[dst];
    }
};