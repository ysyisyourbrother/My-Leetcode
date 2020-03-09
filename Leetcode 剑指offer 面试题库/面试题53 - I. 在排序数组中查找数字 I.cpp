#include "headfile.h"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        // 先二分查找到对应的值，然后往后搜所有一样的个数
        int index = binarysearch(nums,0,nums.size()-1, target);
        int count=0;
        while(index<nums.size() && nums[index]==target)
        {
            index++;
            count++;
        }
        return count;
    }
    int binarysearch(vector<int> & nums, int begin ,int end, int target)
    {
        while(begin<end)
        {
            int mid = (begin+end)/2;//向下取整
            if(nums[mid]>=target)// 如果中间大于，目标，向左边搜索
            {
                end = mid;
                continue;
            }
            else
            {
                begin = mid+1;
                continue;
            }
        }
        if(begin==end)
            return begin;
        else
            return nums.size();
        
    }
};