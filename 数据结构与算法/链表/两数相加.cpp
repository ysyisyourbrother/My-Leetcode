
#include "headfile.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *result = new ListNode(0);//建立一个头节点，方便接下来的链表增添节点
    ListNode *tmp = result;
    int sum = 0;
    while(l1 || l2){      
        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }
        tmp->next = new ListNode(sum%10);
        sum /= 10;
        tmp = tmp->next;
    }
    if(sum)
        tmp->next = new ListNode(1);
    return result->next;
}
