#include "headfile.h"
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    bool  static cmp(Interval a,Interval b)
    {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        if(intervals.size()==0) return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval>::iterator it=intervals.begin();
        vector<Interval>::iterator ite=intervals.end();
        while(it<ite-1)
        {
            if((*it).end>=(*(it+1)).start)
            {
                if((*(it+1)).end<(*it).end)
                {
                    (*(it+1)).start=(*it).start;
                    (*(it+1)).end=(*it).end;
                }
                else
                {
                    (*(it+1)).start=(*it).start;
                }
                it = intervals.erase(it);
                ite=intervals.end();
            }
            else
            {
                it++;
            }
        }
        return intervals;
    }
};
int main()
{

}