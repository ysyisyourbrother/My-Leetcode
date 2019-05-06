#include<iostream>
using namespace std;
template <typename Node_entry>
struct Node {
   Node_entry entry;
   Node *next;
   Node();
   Node(Node_entry item, Node *add_on = NULL);
};

template <typename Node_entry> 
Node<Node_entry>::Node()
{
   next = NULL;
}

template <typename Node_entry> 
Node<Node_entry>::Node(Node_entry item, Node *add_on)
{
   entry = item;
   next = add_on;
}


template<typename T>
Node<T>* copyList( const Node<T> *  head )
{
	Node<T>* lst=NULL;
	Node<T>* newHead=NULL;
	while(head!=NULL)
	{
		if(lst==NULL)
		{
			lst=new Node<T>(head->entry,NULL);
			newHead=lst;
		}
		else
		{
			lst->next=new Node<T>(head->entry,NULL);
			lst=lst->next;
		}	
		head=head->next;
	}
	return newHead;
}
int main()
{
	Node<int>* a = new Node<int>(5,NULL);
	a->next = new Node<int>(6,NULL);
	a->next->next = new Node<int>(7,NULL);
	a->next->next->next = new Node<int>(8,NULL);
	Node<int>* copy = copyList<int>(a);
	while(copy!=NULL)
	{
		cout<<copy->entry<<endl;
		copy=copy->next;
	}
 } 
