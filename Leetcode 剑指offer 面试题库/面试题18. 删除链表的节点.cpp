#include "headfile.h"
using namespace std;
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL) return NULL;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }
        if(pre != NULL) // 如果删除的不是第一个节点
            pre->next = cur->next;
        else
            head = head->next; // 如果删除的是第一个节点，head向下移动一个
        // delete cur; //  删除当前节点的值 leetcode不要求
        return head;
    }
};