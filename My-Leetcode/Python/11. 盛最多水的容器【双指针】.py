# 双指针，关键是理解为什么要移动高度小的一边的指针。
# 因为高度高的一边的指针移动会被限制与小的高度，因此移动后装水量一定小于原来，因此移动没有意义
class Solution:
    def maxArea(self, height):
        res = 0
        if len(height)<2:
            return 0
        i = 0
        j = len(height)-1
        res = 0
        while i<j:
            tmp = min(height[i],height[j])*(j-i)  #求当前情况下可以装的雨水量
            if res < tmp:
                res = tmp
            if height[i]<height[j]:  # 移动小的一边
                i+=1
            else:
                j-=1
        return res



        

a = [1,8,6,2,5,4,8,3,7]
test = Solution()
res = test.maxArea(a)
print(res)

