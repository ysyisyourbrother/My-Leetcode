#include "headfile.h"
using namespace std;
bool isValid(string s) 
{
    stack<char> mysta;
    bool ismatch=true;
    int i=0;
    while(ismatch&&i<s.size())
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            mysta.push(s[i]);
        else if(s[i]==')'||s[i]=='}'||s[i]==']')
            if(mysta.empty()||(mysta.top()=='('&&s[i]!=')')||(mysta.top()=='{'&&s[i]!='}')||(mysta.top()=='['&&s[i]!=']'))
            {
                ismatch=false;
            }
            else
                mysta.pop();
        i++;
    }
    if(!mysta.empty()) ismatch=false;
    return ismatch;
}
int main()
{
    string a="{[]}";
    cout<<isValid(a);
}