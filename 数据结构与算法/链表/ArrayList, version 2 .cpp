#include <iostream>
using namespace std;
typedef int T;
class ArrayList2 {
   public:
    ArrayList2()//构造空线性表
    {
    	elems=NULL;
    	count=0;
		arraySize=0;    	
	}
    ArrayList2(int n)//构造长度（即size）为n的线性表
    {
    	elems = new T[n];
    	count=n;
    	arraySize=n;
	}
    ~ArrayList2()
    {
    	delete []elems;
    	count=0;
    	arraySize=0;
	}
    ArrayList2(const ArrayList2 & c)
    {
    	elems = new T[c.arraySize];
    	for(int i=0;i<c.count;i++)
    	{
    		elems[i]=c.elems[i];
		}
		count=c.count;
		arraySize=c.arraySize;
	}
    const ArrayList2& operator = (ArrayList2 & c)
    {
    	if(elems!=NULL)
    	{
    		delete []elems;
		}
		elems = new T[c.arraySize];
    	for(int i=0;i<c.count;i++)
    	{
    		elems[i]=c.elems[i];
		}
		count=c.count;
		arraySize=c.arraySize;	
		return *this;
	}
    int size() const //返回线性表中元素个数
    {
    	return count;
	}
    int capacity()const//返回数组的容量
    {
    	return arraySize;
	}
    bool full() const //如果表满，返回true, 否则，返回false.
    {
    	return count==arraySize;
	}
    bool empty() const //如果表空，返回true, 否则，返回false.
    {
    	return count==0;
	}
    void clear() //将表置为空表。
    {
    	count=0;
	}
    void traverse(void (*visit)(T &))//将函数 (*visit)应用到表中每个元素上。
    {
    	for(int i=0;i<count;i++)
    	{
    		visit(elems[i]);
		}
	}  
    void retrieve(int position, T &x) const
    {
    	if(0<=position&&position<=size()-1)
    	{
    		x=elems[position];
		}
		else
			return;
	}
    //如果0=<position<=size()-1, 则用x返回位于position的元素
    //否则，动作为空.
    void replace(int position, const T &x)
    {
    	if(0<=position&&position<=size()-1)
    	{
    		elems[position]=x;
		}
		else
			return;
	}
    //如果0=<position<=size()-1, 则将位置position的元素修改成x.
    //否则，动作为空.
    void erase(int position, T &x)
    {
    	if(0<=position&&position<=size()-1)
    	{
    		x=elems[position];
    		for(int i=position;i<count-1;i++)
    		{
    			elems[i]=elems[i+1];
			}
			count--;
		}
		else
			return;
	}
    //如果0=<position<=size()-1, 则将位置position的元素删除，
    //并将删除的元素用x返回，否则，动作为空.
    void erase(int position)
    {
    	if(0<=position&&position<=size()-1)
    	{
    		for(int i=position;i<count-1;i++)
    		{
    			elems[i]=elems[i+1];
			}
			count--;
		}
		else
			return;
	}
    T & operator [] (int position)
    {
    	return elems[position];
	}
    //如果0=<position<=size()-1, 则返回位于position的元素
    //否则，动作为空.
    int find( T &x) const //return the position of the first occurrence of x if it exists, return -1 otherwise.
    {
    	for(int i=0;i<count;i++)
    	{
    		if(elems[i]==x)
    		{
    			return i;
			}
		}
		return -1;
	}
    void push_back(const T &x)//put x after the last item 
    {
    	insert(count,x);
	}
    void insert(int position, const T &x)
    {
    	if(0<=position&&position<=size())
    	{
    		if(full())
    		{
    			T* newlist = new T[arraySize+1];//拓展数组大小,每次拓展5大小 
				for(int i=0;i<position;i++)
				{
					newlist[i]=elems[i];
				} 
				newlist[position]=x;
				for(int i=position+1;i<=count;i++)
				{
					newlist[i]=elems[i-1];
				}
				count++;
				arraySize++;
				delete []elems;
				elems=newlist;
				return;
			}
    		for(int i=count-1;i>=position;i--)
    		{
    			elems[i+1]=elems[i];
			}
			elems[position]=x;
			count++;
		}
		else
			return;
	}
    //如果0=<position<=size(), 则将x插入到位置position.
    //否则，动作为空.
  private:
    T *elems;
    int count; //记录数组elems中存储的元素个数
    int arraySize;//数组长度
};
int main()
{
	ArrayList2 lst1(5);
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(4);
	lst1.push_back(5);
	lst1.push_back(6);
	ArrayList2 lst2(lst1);
	lst2.erase(0);
	lst1=lst2;
	cout<<lst1[0];
	
}
