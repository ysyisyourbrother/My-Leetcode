#include "headfile.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* merge(ListNode* first,ListNode* second)
{
    ListNode *last_sorted;
	ListNode combined(0);
	last_sorted=&combined;
	while(first!=NULL&&second!=NULL)
	{
		if(first->val<=second->val)
		{
			last_sorted->next=first;
			last_sorted=last_sorted->next;
			first=first->next;
		}
		else
		{
			last_sorted->next=second;
			last_sorted=last_sorted->next;
			second=second->next;
		}
	}
	if(first==NULL)
	{
		last_sorted->next=second;
	}
	else
		last_sorted->next=first;
		
	return combined.next;
}
ListNode* mergeKLists(vector<ListNode*>& lists) //归并排序
{
    ListNode* result=new ListNode(0);//建立一个头结点
    if(lists.size()==0) return result->next;

    int begin=0;
    int end=lists.size()-1;
    int mid=(begin+end)/2+1;
    while(end>begin)
    {
        for(int i=0;i<mid;i++)
        {
            if(i+mid<=end)
            {
                lists[i]=merge(lists[i],lists[i+mid]);
            }
        }
        end=mid-1;
        mid=(begin+end)/2+1;
    }
    return lists[0];
}
int main()
{
    ListNode a(1);
    ListNode b(3);
    ListNode c(2);
    ListNode d(4);
    ListNode e(3);
    ListNode f(5);
    a.next=&b;
    c.next=&d;
    e.next=&f;
    vector<ListNode*> lists;
    lists.push_back(&a);
    lists.push_back(&c);
    lists.push_back(&e);
    ListNode* result=mergeKLists(lists);
    while(result!=NULL)
    {
        cout<<result->val<<" ";
        result=result->next;
    }
}
