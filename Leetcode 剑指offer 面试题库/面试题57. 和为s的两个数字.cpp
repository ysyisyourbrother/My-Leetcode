#include "headfile.h"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r=nums.size()-1;
        vector<int> res;
        while(l<r)
        {
            int cur = nums[l]+nums[r];
            if(cur==target)
            {
                res.push_back(nums[l]);
                res.push_back(nums[r]);
                return res;
            }
            else if(cur>target)
                r--;
            else
                l++;
        }
        return res;
    }
};