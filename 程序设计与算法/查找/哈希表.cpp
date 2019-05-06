#include <iostream>
#include <string>
#define is_delete "delete"//定义-2为可以被删除位置但探查不会被终止 
#define is_empty "empty"//定义-1为空，探查会停止 
#define hash_size 245935//定义哈希表的大小为20011
using namespace std;
int Hash(string target)
{
	int value=0;
	for(int i=0;i<target.size();i++)
	{
		value=value*4 + target[i];//利用到了每个字符 
	}
	return value%hash_size;
}
bool insert(string *table,string entry)//插入一个变量 
{
	int probe=Hash(entry),//获取哈希值
	    increment=1, //增量，用来实现二次探查
	    probe_count=0;//探查次数达到表的长度一半时就可以停止了
	while(table[probe]!=is_empty
			&&table[probe]!=is_delete
			&&table[probe]!=entry
			&&probe_count<(hash_size+1)/2){
		probe_count++;
		probe=(probe+increment)%hash_size;//在表长度内循环 
		increment+=2;
	}
	if(table[probe]==is_empty||table[probe]==is_delete)
	{
		table[probe]=entry;
		return 1;
	}
	else if(table[probe]==entry)
	{
		cout<<entry<<"在表中已存在"<<endl; 
		return 0;
	}
	else
	{
		cout<<"表已满，无法插入"<<endl;
		return 0;
	}		
}
int search(string *table,string entry)//和插入操作类似 
{
	int probe=Hash(entry),//获取哈希值
	    increment=1, //增量，用来实现二次探查
	    probe_count=0;//探查次数达到表的长度一半时就可以停止了
	while(table[probe]!=is_empty
			&&table[probe]!=entry
			&&probe_count<(hash_size+1)/2){
		probe_count++;
		probe=(probe+increment)%hash_size;//在表长度内循环 
		increment+=2;
	}
	if(table[probe]==is_empty||!(probe_count<(hash_size+1)/2))
	{
		return hash_size;//不存在的时候返回表的大小 
	}
	else
	{
		return probe; 
	}
}
bool Delete(string *table,string entry)
{
	int pos=search(table,entry);
	if(pos==hash_size)
	{
		cout<<"元素不存在,删除失败"<<endl;
		return 0;
	}
	else
	{
		table[pos]=is_delete;
		return 1;
	}
}

int main()
{
	string table[hash_size];
	for(int i=0;i<hash_size;i++)
	{
		table[i]=is_empty;
	}
	insert(table,"ysy");
	insert(table,"zy");
	insert(table,"520");
	insert(table,"110");
	insert(table,"990");
	cout<<search(table,"ysy")<<endl;
	Delete(table,"ysy");
	cout<<search(table,"ysy");
	
} 
