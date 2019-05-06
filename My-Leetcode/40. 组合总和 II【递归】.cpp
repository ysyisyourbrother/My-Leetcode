#include "headfile.h"
using namespace std;
void recursion(int start,vector<vector<int> > &Result,vector<int> res,vector<int>& candidates,int target)
{
	int tar=target;
	for(int i = start;i<candidates.size();i++)
	{
		if(i>start&&candidates[i]==candidates[i-1]) continue;//关键步骤
		if(tar>=candidates[i])
		{
			
			res.push_back(candidates[i]);
			recursion(i+1,Result,res,candidates,tar-candidates[i]);
			res.pop_back();
		}
	}
	if(target==0)
	{
		Result.push_back(res);
	}
}
vector<vector<int> > combinationSum2(vector<int>& candidates, int target) 
{
	vector<vector<int> > result;
	if(candidates.size()==0)
	{
		return result;
	}
	sort(candidates.begin(),candidates.end());
	vector<int> res;
	recursion(0,result,res,candidates,target);
	unique(result.begin(),result.end());
	
	return result;
}

int main()
{
	vector<int> a;
	a.push_back(10);
	a.push_back(1);
	a.push_back(2);
	a.push_back(7);a.push_back(6);a.push_back(1);a.push_back(5);
    vector<vector<int> > res = combinationSum2(a,8);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

}

	