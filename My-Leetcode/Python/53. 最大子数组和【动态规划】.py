class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        cur_max = 0
        for i in range(len(nums)):
            if nums[i] >= cur_max + nums[i]:
                cur_max = nums[i]
            else:
                cur_max += nums[i]
            res = max(res, cur_max)
        return res
