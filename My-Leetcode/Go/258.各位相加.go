/*
 * @lc app=leetcode.cn id=258 lang=golang
 *
 * [258] 各位相加
 */

// @lc code=start
func addDigits(num int) int {
	if num == 0 {
		return 0
	}

	res := num % 9
	if res == 0 {
		return 9
	}

	return res
}

// @lc code=end

