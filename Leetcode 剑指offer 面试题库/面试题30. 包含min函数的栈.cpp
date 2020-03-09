#include "headfile.h"
using namespace std;
class MinStack {
public:
    stack<int> mysta1; // 存放数据
    stack<int> mysta2; // 存放最小值 
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        mysta1.push(x);
        if(!mysta2.empty())
        {
            int top = mysta2.top();
            // 如果mysta2的顶部元素比x要大，就push
            if(x<=top)
                mysta2.push(x);
        }
        else
        {
            mysta2.push(x); // 如果是空的，直接push
        }
    }
    
    void pop() {
        if(!mysta1.empty()) // 如果mysta1不是空的，就可以pop
        {
            int top = mysta1.top();
            mysta1.pop();
            if(top == mysta2.top()) // mysta1不为空，mysta2一定也不为空
                mysta2.pop();
        }
    }
    
    int top() {
        if(!mysta1.empty())
            return mysta1.top();
        return -1;
    }
    
    int min() {
        if(!mysta2.empty())
            return mysta2.top();
        return -1;// 如果不存在最小值 返回0
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main()
{
    string a ="123";
    a[2] = '2';
    cout<<a;
}