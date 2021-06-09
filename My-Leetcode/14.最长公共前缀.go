/*
 * @lc app=leetcode.cn id=14 lang=golang
 *
 * [14] 最长公共前缀
 */

// @lc code=start
func longestCommonPrefix(strs []string) string {
	var count int = -1
	var flag bool = true
	for flag {
		count += 1
		var c byte
		if count < len(strs[0]) {
			c = strs[0][count]
		} else {
			break
		}
		for i := 1; i < len(strs); i++ {
			if !(count < len(strs[i]) && strs[i][count] == c) {
				flag = false
				break
			}
		}
	}
	return strs[0][:count]
}

// @lc code=end

