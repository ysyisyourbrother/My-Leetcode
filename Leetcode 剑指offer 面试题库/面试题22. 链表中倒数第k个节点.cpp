class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int count = k-1;
        ListNode * res = head; // 双指针，先找到第k个元素，然后一个指向第k个，一个指向第一个，同时向右
        while(head!=NULL && count > 0)
        {
            count --;
            head = head->next;
        }
        if(head == NULL) return NULL; // 如果链表本身长度小于k，返回空
        while(head->next!=NULL)
        {
            head = head->next;
            res = res->next;
        }
        return res;
    }
};