#include <iostream>
#include <vector>
using std::cout;
using std::vector;
//typedef vector<int> set;  //don't submit this line.
/*
Assume that A and B are sets , which are  integers of increasing order,  it returns the intersection of A and B .
For example, A = (2,3,5,12), B = (3,5,8,9), then the result returned is (3,5).
*/
set setIntersection(const set &A, const set &B)
{
    set Interset;
    int i=0,j=0;
    while(i<A.size()&&j<B.size())
    {
    	if(A[i]==B[j])
    	{
    		Interset.push_back(A[i]);
    		i++;
    		j++;
		}
		else if(A[i]>B[j])
		{
			j++;
		}
		else
		{
			i++;
		}
	}
    return Interset;
}
int main()
{
    set A;
    A.push_back(2);
    A.push_back(3);
    A.push_back(5);
    A.push_back(12);
    set B;
    B.push_back(3);
    B.push_back(5);
    B.push_back(8);
    B.push_back(9);
    set Interset=setIntersection(A,B);
    for(int i=0;i<Interset.size();i++)
    {
    	cout<<Interset[i]<<" ";
	}
}
