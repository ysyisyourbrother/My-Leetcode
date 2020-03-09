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

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size()<=0) return res;
        else if(nums.size()<k)
        {
            res.push_back(*max_element(nums.begin(),nums.end())); // 如果数量不足k个，直接获取最大元素返回
            return res;
        }
        // 如果nums的数量大于k个，执行滑动窗口
        MaxQueue que; // 定义一个可以立刻获取最大值的队列
        int end = k-1; // 定义滑动窗口初始位置
        for(int i =0;i<k;i++)
        {
            que.push_back(nums[i]);
        }
        while(1)
        {
            res.push_back(que.max_value());// 获取当前窗口的最大值

            if(++end>==nums.size()) break;
            que.pop_front(); // 去掉队头元素
            que.push_back(nums[end]); //加入新的元素
        }
        return res;
    }
};