#include "headfile.h"
using namespace std;
#define interval1 2*numRows-2
#define interval2 2*numRows-2-2*i
string convert(string s, int numRows)  //逐个找要输出的字符在原来字符串的位置  找规律
{
	if(numRows==1) return s;
	string res;
	for(int i=0;i<numRows;i++)
	{
		int pos=i;
		if(i==0||i==numRows-1)
		{
			while(pos<s.length())
			{
				res+=s[pos];	
				pos+=interval1;
			}
		}
		else
		{
			int times=0;
			while(pos<s.length())
			{
				if(times%2==0)
				{
					res+=s[pos];
					pos+=interval2;
					times++;
				}
				else
				{
					res+=s[pos];
					pos+=2*i;
					times++;
				}
			}
		}
	}
	return res;
}
int main()
{
	string s="A";
	int numRows=1;
	cout<<convert(s,numRows);
}