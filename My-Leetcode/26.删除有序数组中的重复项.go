/*
 * @lc app=leetcode.cn id=26 lang=golang
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	count := 0
	slow, fast := 0, 0
	for fast < len(nums) {
		for fast+1 < len(nums) && nums[fast] == nums[fast+1] {
			fast += 1
		}
		nums[slow] = nums[fast]
		fmt.Println(nums[slow])
		fast += 1
		slow += 1
		count += 1
	}
	return count
}

// @lc code=end

