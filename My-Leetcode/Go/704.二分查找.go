/*
 * @lc app=leetcode.cn id=704 lang=golang
 *
 * [704] 二分查找
 */

// @lc code=start
func search(nums []int, target int) int {
	l := 0
	r := len(nums) - 1
	for l < r {
		mid := (l + r) / 2
		if target <= nums[mid] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if nums[r] == target {
		return r
	}
	return -1
}

// @lc code=end

