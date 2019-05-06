#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;

void MinHeap(vector<int> &v,int i,int height)
{
	int left=2*i+1;
	int right=2*i+2;
	int smallest=i;
	if(v[left]<v[i]&&left<=height)
	{
		smallest=left;
	}	
	if(v[smallest]>v[right]&&right<=height)
	{
		smallest=right;
	}
	if(smallest!=i)
	{
		swap(v[smallest],v[i]);
		MinHeap(v,smallest,height);
	}
}
void buildMinHeap(vector<int> &v)
{
	for(int i=(v.size()-1)/2;i>=0;i--)
	{
		MinHeap(v, i,v.size()-1);
	}
}
int select_kth_smallest(vector<int> v, size_t k)
{
	buildMinHeap(v);
	int height=v.size()-1;
	while(k--)
	{
		swap(v[0],v[height]);
		height--;
		MinHeap(v,0,height);
	}
	return v[height+1];
}
int main()
{
	vector<int> vec;
	for(int i=17;i>=4;i--)
	{
		vec.push_back(i);
	}
	cout<<select_kth_smallest(vec,4);
} 
