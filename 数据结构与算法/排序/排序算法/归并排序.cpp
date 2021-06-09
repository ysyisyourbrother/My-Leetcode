#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct Node//链表归并排序的结点 
{
	Node* next;
	int entry;
	Node(int entry=0,Node *next=NULL):next(next),entry(entry){}
};
void merge_Sort1(int *arr,int low,int high)//归并排序数组实现 
{
	if(low>=high)
		return;
	if(low+1==high)
	{
		if(arr[low]>arr[high])
			swap(arr[low],arr[high]); 
		return; 
	}
	int mid=floor((low+high)/2);//将数组分割成两半
	//分别对两边的数组进行归并排序 
	merge_Sort1(arr,low,mid);
	merge_Sort1(arr,mid+1,high);
	//归并排序完后需要合并两者
	vector<int> temp;
	int i=low;
	int j=mid+1;
	while(i!=mid+1&&j!=high+1)
	{
		if(arr[i]<arr[j])
		{
			temp.push_back(arr[i]);
			i++; 
		}
		else
		{
			temp.push_back(arr[j]);
			j++;
		}		
	}
	if(i==mid+1)//将剩下的也并入 
	{
		for(;j!=high+1;j++)
		{
			temp.push_back(arr[j]);
		}
	}
	else
	{
		for(;i!=mid+1;i++)
		{
			temp.push_back(arr[i]);
		}
	}
	for(int i=low;i<=high;i++)
	{
		arr[i]=temp.front();
		temp.erase(temp.begin());
	} 
	
}

void print(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->entry<<" ";
		head=head->next;
	}
}
Node* divide_from(Node *sub_list);
Node* merge(Node *first,Node *second);
void merge_Sort2(Node *&sub_list)
{
	if(sub_list!=NULL&&sub_list->next!=NULL)
	{
		Node *second_half = divide_from(sub_list);
//		print(sub_list);
//		print(second_half);
		merge_Sort2(sub_list);
		merge_Sort2(second_half);
		sub_list=merge(sub_list,second_half);
	}
}
Node* divide_from(Node *sub_list)//找链表中点的算法 
{
	Node* position;
	Node* midpoint;
	Node* second_half;
	if((midpoint=sub_list)==NULL) return NULL;
	position=midpoint->next;
	while(position!=NULL)
	{
		position=position->next;
		if(position!=NULL)
		{
			midpoint=midpoint->next;
			position=position->next;
		}
	}
	second_half=midpoint->next;
	midpoint->next=NULL;
	return second_half;
}
Node* merge(Node *first,Node *second)
{
	Node *last_sorted;
	Node combined;//哑结点 
	last_sorted=&combined;
	while(first!=NULL&&second!=NULL)
	{
		if(first->entry<=second->entry)
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
void test1()
{
	int size=3;
	int arr[]={5,1,3,9,1,10,3,9};
	int arr1[]={3,2,1};
	merge_Sort1(arr1,0,size-1);
	for(int i=0;i<size;i++)
		cout<<arr1[i]<<" ";
}
void test2()
{
	Node *a=new Node(4);
	Node *b=new Node(6,a);
	Node *c=new Node(1,b);
	Node *d=new Node(3,c);
	Node *e=new Node(9,d);
	Node *f=new Node(0,e);
	Node *g=new Node(2,f);
	merge_Sort2(g);
	print(g);
	
	
}
int main()
{
	test2();
}
 
 
