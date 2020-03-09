#include "headfile.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newptr = new ListNode(-1);
        ListNode * cur = newptr;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                // 将l1的元素加入
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                // 将l2的元素加入
                cur->next = l2;
                l2 = l2->next; 
            }
            cur=cur->next;
        }
        if(l1==NULL)
        {
            cur->next = l2;
        }
        else
        {
            cur->next = l1;
        }
        return newptr->next;
    }
};