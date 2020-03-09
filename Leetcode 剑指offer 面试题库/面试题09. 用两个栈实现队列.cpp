# include "headfile.h"
using namespace std;
class CQueue {
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        if(mysta1.empty())// 如果栈1是空的，说明栈2不是空的，把栈2倒过来
        {
            while(!mysta2.empty())
            {
                int tmp = mysta2.top();
                mysta1.push(tmp);
                mysta2.pop();
            }
        }
        mysta1.push(value);
    }
    
    int deleteHead() {
        if(mysta2.empty())// 同上
        {
            while(!mysta1.empty())
            {
                int tmp = mysta1.top();
                mysta2.push(tmp);
                mysta1.pop();
            }
        }
        if(mysta2.empty())
            return -1;
        int res = mysta2.top();
        mysta2.pop();
        return res;   
    }
private:
    stack<int> mysta1;  //  1号栈是队尾在栈顶
    stack<int> mysta2;  //  2号栈是队头在栈顶
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */