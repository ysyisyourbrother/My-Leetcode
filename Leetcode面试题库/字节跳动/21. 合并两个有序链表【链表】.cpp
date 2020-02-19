#include "headfile.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* res = new ListNode(-1); // 定义一个空头部，方便操作
        ListNode* cur = res; // 要返回的有序列表组装的当前位置
        while(!(tmp1 == NULL || tmp2 == NULL)) // 如果同时为非NULL 进行比较操作
        {
            if(tmp1->val > tmp2->val)// tmp2比较小，先将tmp2的加入res链表中
            {
                cur->next = tmp2;
                tmp2 = tmp2->next;
                cur = cur->next;
            }
            else
            {
                cur->next = tmp1;
                tmp1 = tmp1->next;
                cur = cur->next;
            }
        }
        if(tmp1==NULL) // 如果tmp1为空，就直接将tmp2接在res后面即可
        {
            cur->next = tmp2;
        }
        if(tmp2 == NULL)
        {
            cur->next = tmp1;
        }
        return res->next;
    }
};