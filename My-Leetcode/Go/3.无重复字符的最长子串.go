/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	myMap := map[byte]int{}
	var maxLen, curLen int
	for i := 0; i < len(s); i++ {
		if index, ok := myMap[s[i]]; ok {
			if curLen > maxLen {
				maxLen = curLen
			}
			i = index
			myMap = map[byte]int{}
			curLen = 0
		} else {
			curLen += 1
			myMap[s[i]] = i
		}
	}
	if curLen > maxLen {
		maxLen = curLen
	}
	return maxLen
}

// @lc code=end

