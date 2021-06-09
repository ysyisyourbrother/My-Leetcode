#include "headfile.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        int _k = k-1; // 记录当前值
        ListNode* front = head; //前面的指针
        while(_k--)// 向前k次
            front = front->next;
        
        // 如果链表有k个节点，双指针同时向后遍历
        ListNode* pre = head;
        while(front->next!=NULL)
        {
            front = front->next;
            pre = pre->next;
        }
        return pre->val;
    }
};