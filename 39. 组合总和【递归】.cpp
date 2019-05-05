#include "headfile.h"
using namespace std;
void recursion(int i,vector<vector<int> > &Result,vector<int> res,vector<int>& candidates,int target)
{
	int tar=target;
	for(;i<candidates.size();i++)
	{
		if(tar>=candidates[i])
		{
			res.push_back(candidates[i]);
			recursion(i,Result,res,candidates,tar-candidates[i]);
			res.pop_back();
		}
	}
	if(target==0)
	{
		Result.push_back(res);
	}
}
vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
{
	vector<vector<int> > result;
	if(candidates.size()==0)
	{
		return result;
	}
	vector<int> res;
	recursion(0,result,res,candidates,target);
	
	return result;
}

int main()
{
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(6);
	a.push_back(7);
    vector<vector<int> > res = combinationSum(a,7);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

}

	