#include "headfile.h"
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> mysta;// 辅助栈
        int ptr1 = 0, ptr2 = 0;
        while(ptr2 < popped.size())
        {
            if(ptr1<pushed.size() && pushed[ptr1] == popped[ptr2]) // 如果pushed元素和目标相等， 则压入后立刻弹出即可满足
            {
                ptr1++;
                ptr2++;
            }
            else if(!mysta.empty() && mysta.top() == popped[ptr2]) // 如果栈顶的元素和目标相等
            {
                ptr2++;
                mysta.pop();
            }
            else if(ptr1!=pushed.size()) // 如果都不满足,但队列还没空，则压入栈中
            {
                mysta.push(pushed[ptr1]);
                ptr1++;
            }
            else if(ptr1 == pushed.size())
            {
                return false;
            }
        }
        return true;
    }
};