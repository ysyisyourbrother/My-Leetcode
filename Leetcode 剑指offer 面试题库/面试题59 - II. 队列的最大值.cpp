#include "headfile.h"
using namespace std;
class MaxQueue {
public:
    queue<int> Queue;// 维护数据的队列
    deque<int> max_Queue; // 维护最大值的队列
    MaxQueue() {}
    
    int max_value() {
        if(Queue.empty()) return -1;
        // 获取当前最大值
        return max_Queue.front();
    }
    
    void push_back(int value) {
        Queue.push(value);
        while(!max_Queue.empty() && value>max_Queue.back())
            max_Queue.pop_back();
        max_Queue.push_back(value);
    }
    
    int pop_front() {
        if(Queue.empty()) return -1;
        int tmp = Queue.front();
        Queue.pop();
        if(tmp == max_Queue.front())
            max_Queue.pop_front();
        return tmp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */