#include "headfile.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* newhead;
    // 递归法实现
    ListNode* reverseList(ListNode* head) {
        helper(head);
        return newhead;
    }
    ListNode* helper(ListNode* head){
        if(head == NULL) return NULL;
        if(head->next == NULL)
        {
            this->newhead = head;
            return head;
        }
        ListNode* node = helper(head->next);
        node->next = head;
        head->next = NULL;
        return head;
    }
};


class Solution2 {
public:
    // 用迭代法解决
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL, *pre = head;
        while (pre != NULL) {
            ListNode* t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }
};