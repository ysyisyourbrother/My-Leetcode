#include "headfile.h"
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) 
	{
		//二者有一个长度为0
		if(s.size()==0)
		{
			// cout<<"hi";
			// system("pause");
			if(p.size()%2==0)
			{
				for(int i=1;i<p.size();i+=2)
				{
					if(p[i]!='*') return false;
				}
				return true;
			}
			else
				return false;
		}
		else
			if(p.size()==0) return false;
		//下面的情况是长度都不为0
		int lens=s.size()-1,lenp=p.size()-1;
		if(p[lenp]!='*')
		{
			if((p[lenp]==s[lens])||p[lenp]=='.')
			{
				return isMatch(s.substr(0,lens),p.substr(0,lenp));
			}
		}
		else//p末尾为*
		{
			//如果倒数第二位是*怎么办？
			if(p.size()==1) return false;
			while(lenp-1>=0&&p[lenp-1]=='*') lenp--;
			if(p[lenp-1]!='.'&&p[lenp-1]!=s[lens])//末尾两位都不匹配
			{
				// cout<<"s:"<<s<<" p:"<<p<<endl;
				// system("pause");
				return isMatch(s,p.substr(0,lenp-1));
			}
			else
			{
				// cout<<"s:"<<s<<" p:"<<p<<endl;
				// system("pause");
				return isMatch(s,p.substr(0,lenp-1))||isMatch(s.substr(0,lens),p);
			}
			
		}
		return false;
    }
};
int main()
{
	Solution test;
	string a="aab";
	string b="c*a*b";
	cout<<test.isMatch(a,b);

}