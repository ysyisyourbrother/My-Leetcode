#include "headfile.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    // 迭代的方法实现反转列表
    ListNode* reverseList1(ListNode* head) 
    {
        ListNode* cur = head;
        ListNode* res = NULL;
        while(cur != NULL)
        {
            ListNode* tmp = new ListNode(*cur);
            tmp->next = res;
            res = tmp;
            cur = cur->next;
        }
        return res;
    }

    // 使用递归的方法反转链表
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL,head);
    }
    ListNode* reverse(ListNode *pre,ListNode *cur){
        if(cur==NULL) return pre;
        ListNode* next = cur->next;
        cur->next = pre;
        return reverse(cur,next);
    }
};