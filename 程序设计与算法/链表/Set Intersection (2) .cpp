#include <iostream>
#include <list>
using namespace std;
//typedef list<int> set;  //don't submit this line
/*
Assume that A and B are sets , which are  integers of increasing order,  it returns the intersection of A and B .
For example, A = (2,3,5,12), B = (3,5,8,9), then the result returned is (3,5).
*/
set setIntersection(const set &A, const set &B)
{
	set::const_iterator irA = A.begin();
	set::const_iterator irB = B.begin();
	set ans;
	while(irA!=A.end()&&irB!=B.end())
	{
		if(*irA==*irB)
		{
			ans.push_back(*irA);
			irA++;
			irB++;
		}
		else if(*irA>*irB)
		{
			irB++;
		}
		else
		{
			irA++;
		}
	}
	return ans;	
}
int main()
{
	set A,B;
	A.push_back(2);
	A.push_back(3);
	A.push_back(5);
	A.push_back(12);
	B.push_back(3);
	B.push_back(5);
	B.push_back(8);
	B.push_back(9);
	set ans = setIntersection(A,B);
	
	set::iterator i;
	for(i=ans.begin();i!=ans.end();i++)
	{
		cout<<*i<<" ";
	}
} 
