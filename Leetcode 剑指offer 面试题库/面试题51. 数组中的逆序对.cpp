class Solution {
public:
    int count; // 统计有多少个逆序对
    Solution():count(0){}

    int reversePairs(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        helper(nums,0,nums.size()-1);
        return count;
    }
    // 使用归并排序的方法
    void helper(vector<int>& nums, int i, int j)
    {
        if(i>=j) return; 
        int mid = (i+j)/2; // 取中间位置的值

        // 递归归并排序
        helper(nums,i,mid);
        helper(nums,mid+1,j);

        // 合并排序结果，同时统计逆序对数量
        int x = i;
        int y = mid+1;
        vector<int> tmp;
        while(x<=mid && y<=j)
        {
            if(nums[x]<=nums[y])// 如果左边小于右边 不统计逆序对
            {
                tmp.push_back(nums[x]);
                x++;
            }
            if(nums[x]>nums[y]) // 左边大于右边，统计逆序对
            {
                tmp.push_back(nums[y]);
                count = count + mid-x+1;
                y++;
            }
        }
        if(x>mid) // 如果前面的先用完，把后面的全部加入
            for(int p = y; p <=j;p++)
                tmp.push_back(nums[p]);
        else
            for(int p = x; p <=mid;p++)
                tmp.push_back(nums[p]);
        // 将排好序的结果替换进原来的nums中
        for(int p =0;p<tmp.size();p++)
            nums[i+p] = tmp[p];
    }
};