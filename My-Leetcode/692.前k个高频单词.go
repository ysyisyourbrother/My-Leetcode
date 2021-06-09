/*
 * @lc app=leetcode.cn id=692 lang=golang
 *
 * [692] 前K个高频单词
 */

// @lc code=start
func topKFrequent(words []string, k int) []string {
	count := make(map[string]int)
	for i := 0; i < len(words); i++ {
		count[words[i]] += 1
	}
	uniqueWords := make([]string, 0)
	for w := range count {
		uniqueWords = append(uniqueWords, w)
	}
	sort.Slice(uniqueWords, func(i, j int) bool {
		s, t := uniqueWords[i], uniqueWords[j]
		return count[s] > count[t] || (count[s] == count[t] && s < t)
	})
	return uniqueWords[:k]

}

// @lc code=end

