/*
 * @lc app=leetcode.cn id=4 lang=golang
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n := len(nums1) + len(nums2)
	curNum := 0
	var i, j int = 0, 0
	var last, cur float64
	for i < len(nums1) || j < len(nums2) {
		var n1, n2 float64
		last = cur
		if i == len(nums1) {
			n1 = math.Inf(1)
		} else {
			n1 = float64(nums1[i])
		}
		if j == len(nums2) {
			n2 = math.Inf(1)
		} else {
			n2 = float64(nums2[j])
		}

		if n1 < n2 {
			cur = n1
			i += 1
		} else {
			cur = n2
			j += 1
		}
		curNum += 1
		if curNum > n/2 {
			if n%2 == 0 { // 若总数为偶数
				return (last + cur) / 2.0
			} else {
				return cur
			}
		}
	}
	return 0.0
}

// @lc code=end

