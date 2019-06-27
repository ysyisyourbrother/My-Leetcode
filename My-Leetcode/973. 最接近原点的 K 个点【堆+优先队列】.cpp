#include "headfile.h"
using namespace std;
/*
    方法1 自己构建一个最小堆，并每次从最小堆顶部取一个元素加入返回的向量。
          这个方法很慢，但可以自己尝试实现一遍最小堆
 */
class Solution {
public:
    void Swap(vector<int>& a,vector<int>& b)
    {
        int tem=a[0];
        a[0]=b[0];
        b[0]=tem;
        tem=a[1];
        a[1]=b[1];
        b[1]=tem;
    }
    double C(vector<int> Aim)
    {
        return Aim[0]*Aim[0]+Aim[1]*Aim[1];
    }
    void buildheap(vector<vector<int>>& points,int cur,int len)// cur是当前的顶点的序号  len是当前还没有排序的顶点数量
    {   
        int Minpos=cur;
        if(2*cur+1<len&&C(points[2*cur+1])<C(points[Minpos]))// 如果这个点合法且小于cur点的欧拉距离 
            Minpos=2*cur+1;
        if(2*cur+2<len&&C(points[2*cur+2])<C(points[Minpos]))
            Minpos=2*cur+2;
        Swap(points[cur],points[Minpos]);
        if(cur!=Minpos) // 如果发生交换，往被交换的那一边继续递归建造
            buildheap(points,Minpos,len);
    }   
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        if(points.size()==0) return res;
        int n=points.size();// 总顶点的个数
        for(int i=n/2-1;i>=0;i--)
            buildheap(points,i,n);//建立初始堆
        for(int i=0;i<K;i++)//执行K次每次取最小的
        {
            res.push_back(points[0]);
            Swap(points[0],points[n-1-i]);// 和最后一个位置的顶点交换位置
            buildheap(points,0,n-i-1);
        }
        return res;
    } 
};
/*
    使用C++库的优先队列实现
 */
class Solution2 {
public:
    struct node // 自己定义的结构体 一定要重载比较运算符号
    {
        int index;
        int Dis;
        bool operator <(node a)const //这里必须是const的函数
        {
            return Dis>a.Dis;
        }
        node(int a,int b):index(a),Dis(b){}
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        if(points.size()==0) return res;
        priority_queue <node> Q; //定义一个优先队列，其中node中必须定义了<运算符
        for(int i=0;i<points.size();i++)
        {
            node a(i,points[i][0]*points[i][0]+points[i][1]*points[i][1]); 
            Q.push(a);
        }
        for(int i=0;i<K;i++)
        {
            res.push_back(points[Q.top().index]);
            Q.pop();
        }
        return res;
    } 
};
int main()
{

}