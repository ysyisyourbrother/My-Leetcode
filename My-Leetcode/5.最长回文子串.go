/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 */

// @lc code=start
func longestPalindrome(s string) string {
	n := len(s)
	if n == 0 {
		return ""
	}

	var maxLen int
	var res string
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}

	// 动态规划
	for l := 1; l <= n; l++ { // 遍历子串长度
		for i := 0; i < n-l+1; i++ {
			j := i + l - 1 //计算右指针
			if s[i] == s[j] {
				if i+1 > j-1 {
					matrix[i][j] = 1
				} else {
					matrix[i][j] = matrix[i+1][j-1]
				}
				if matrix[i][j] == 1 && j-i+1 > maxLen {
					maxLen = j - i + 1
					res = s[i : j+1]
				}
			}
		}
	}
	return res
}

// @lc code=end

