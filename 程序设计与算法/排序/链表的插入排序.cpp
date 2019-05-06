#include "headfile.h"
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void insert_sort(ListNode* head)
{
	int current_val=head->val;
	ListNode* current=head;
	while(current->next!=NULL&&current->next->val<current_val)
	{
		current->val=current->next->val;
		current=current->next;
	}
	current->val=current_val;

}
ListNode* insertionSortList(ListNode* head) 
{
	if(head==NULL) return NULL;
	ListNode* current=head;
	while(current->next!=NULL)//先找到最后一个节点
	{
		current=current->next;
	}
	//从最后一个节点开始排序 排到头结点位置停止
	while(current!=head)
	{
		insert_sort(current);
		ListNode* temp=current;
		current=head;
		while(current->next!=temp)
		{
			current=current->next;
		}
	}
	insert_sort(head);
	return head;
}

