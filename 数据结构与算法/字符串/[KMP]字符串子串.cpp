#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
//KMP算法 
void makeNext(vector<int> P,int *next)
{
    int q,k;
    int m = P.size();
    next[0] = 0;
    for (q = 1,k = 0; q < m; ++q)
    {
        while(k > 0 && P[q] != P[k])
            k = next[k-1];
        if (P[q] == P[k])
        {
            k++;
        }
        next[q] = k;
    }
}

void kmp(vector<int> T,vector<int> P,int *next)
{
    int n,m;
    int i,q;
    n = T.size();
    m = P.size();
    makeNext(P,next);
    for (i = 0,q = 0; i < n; ++i)
    {
        while(q > 0 && P[q] != T[i])
            q = next[q-1];
        if (P[q] == T[i])
        {
            q++;
        }
        if (q == m) // 输出找到的位置  还可以判断i == n - 1 未找到
        {
            cout<<i-m+1<<endl;
            return;
        }
        if(i==n-1)
        {
        	cout<<"no solution"<<endl;
        	return;
		}
    }    
}

int main()
{
	int N;
	while(cin>>N)
	{
		int next[1000]={0};
   		vector<int> T;
    	vector<int> P;//P是子串，T是母串 
		for(int i=0;i<N;i++)
		{
			int a;
			cin>>a;
			P.push_back(a);
		}
		int M;
		cin>>M;
		for(int i=0;i<M;i++)
		{
			int a;
			cin>>a;
			T.push_back(a);
		}
		makeNext(P,next);
   		kmp(T,P,next);
	}
    
    return 0;
}
