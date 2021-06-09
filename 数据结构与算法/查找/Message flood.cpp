#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#define is_empty "empty"//定义空，探查会停止 
#define Hash_size 24593//定义哈希表的大小为20011
using namespace std;
int Hash(string target)
{
	int value = 0;
	for (int i = 0; i<target.size(); i++)
	{
		value = value * 4 + target[i];//利用到了每个字符 
	}
	return value % Hash_size;
}
bool insert(string *table, string entry)//插入一个变量 
{
	int probe = Hash(entry),//获取哈希值
		increment = 1, //增量，用来实现二次探查
		probe_count = 0;//探查次数达到表的长度一半时就可以停止了
	while (table[probe] != is_empty
		&& table[probe] != entry
		&& probe_count<(Hash_size + 1) / 2) {
		probe_count++;
		probe = (probe + increment) % Hash_size;//在表长度内循环 
		increment += 2;
	}
	if (table[probe] == is_empty)
	{
		table[probe] = entry;
		return 1;
	}
	return 0;
}
int search(string *table, string entry)//和插入操作类似 
{
	int probe = Hash(entry),//获取哈希值
		increment = 1, //增量，用来实现二次探查
		probe_count = 0;//探查次数达到表的长度一半时就可以停止了
	while (table[probe] != is_empty
		&& table[probe] != entry
		&& probe_count<(Hash_size + 1) / 2) {
		probe_count++;
		probe = (probe + increment) % Hash_size;//在表长度内循环 
		increment += 2;
	}
	if (table[probe] == is_empty || !(probe_count<(Hash_size + 1) / 2))
	{
		return -1;//不存在的时候返回-1 
	}
	else
	{
		return probe;
	}
}
int main()
{
	int n, m;
	while (cin >> n && n != 0)
	{
		cin >> m;
		string table[Hash_size];
		for (int i = 0; i < Hash_size; i++)
		{
			table[i] = is_empty;
		}
		string temp;
		int pos;
		int count = 0;
		int hold = n;
		while (hold--)
		{
			cin >> temp;
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			insert(table, temp);
		}
		set<string> arr;
		while (m--)
		{
			cin >> temp;
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			arr.insert(temp);
		}
		set<string>::iterator it = arr.begin();
		for (; it != arr.end(); it++)
		{
			pos = search(table, *it);
			if (pos != -1)
			{
				count++;
			}
		}
		cout << n - count << endl;
	}
}
