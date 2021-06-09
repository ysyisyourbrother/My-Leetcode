using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<=1) return nums; //如果数组的大小小于等于1 直接返回
        for(int i =1;i<nums.size();i++)
        {
            int tmp = nums[i];
            int j = i-1;
            while(j>=0 && tmp<nums[j])
                // 如果当前位置比tmp要大，将它向后移动
                nums[j+1] = nums[j],j--;
            // 停止后，现在的空位就是tmp应该处于的位置
            nums[j+1] = tmp;
        }
        return nums;
    }
};

int main()
{
    vector<int> q = {5,2,3,1};
    Solution test;
    test.sortArray(q);
    for(auto i:q)
        cout<<i<<" ";
}