#include "headfile.h"
using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
{
    stack<int> a;
    int j=0;//poped序列的判断下标
    int i=0;
    while(j<popped.size())
    {
        if(a.empty())
        {
            a.push(pushed[i]);
            i++;
            continue;
        }
        if(a.top()==popped[j])
        {
            a.pop();
            j++;
        }
        else
        {
            if(i==pushed.size())
            {
                return false;
            }
            else
            {
                a.push(pushed[i]);
                i++;
            }
        }

    }
    return true; 
}
int main()
{

}