# include "headfile.h"
using namespace std; 
class Solution {
public:
    // 暴力法：对于数组中的每个元素，我们找出下雨后水能达到的最高位置，等于两边最大高度的较小值减去当前高度的值
    int trap1(vector<int>& height)
    {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--) { //Search the left part for max bar size
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < size; j++) { //Search the right part for max bar size
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }

    // 改进版暴力法，暴力法中每次都要找到对某个位置i，左边最大值和右边最大值。
    // 在暴力方法中，我们仅仅为了找到最大值每次都要向左和向右扫描一次。但是我们可以提前存储这个值
    int trap2(vector<int>& height)
    {
        if(height == null)
            return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
    
    // 双指针 思想还是改进的暴力法，但改进的暴力法中，要先从左再从右遍历一次得到左边最高和右边最高的两个列表
    // 现在用一次遍历的方法解决：
    // 左右两个指针同时遍历，每次都是小的一侧指针向中间移动，遇到坑就填水。直到两个指针相遇。
    int trap3(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0; // 记录左右两个指针的当前的最大值
        while (left < right) {// 直到两个指针相遇就停
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]); // 判断是否是坑，是坑就填水
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }

};