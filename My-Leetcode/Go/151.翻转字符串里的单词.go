/*
 * @lc app=leetcode.cn id=151 lang=golang
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
// 使用go库函数翻转
func reverseWords(s string) string {
	res := strings.Fields(s)
	length := len(res)
	for i := 0; i < length/2; i++ {
		res[i], res[length-1-i] = res[length-1-i], res[i]
	}
	return strings.Join(res, " ")
}

// @lc code=end

