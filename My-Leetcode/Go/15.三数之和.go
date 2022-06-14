/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 三数之和
 */

// @lc code=start
func threeSum(nums []int) [][]int {
	n := len(nums)
	sort.Ints(nums) // 排序
	res := make([][]int, 0)
	for x := 0; x < n-2; x++ {
		if nums[x] > 0 {
			break
		}
		if x > 0 && nums[x] == nums[x-1] {
			continue
		}
		y := x + 1
		z := n - 1
		for y < z {
			if nums[x]+nums[y]+nums[z] == 0 {
				res = append(res, []int{nums[x], nums[y], nums[z]})
				y += 1
				for y < z && nums[y-1] == nums[y] {
					y += 1
				}
			} else if nums[x]+nums[y]+nums[z] > 0 {
				z -= 1
				for y < z && nums[z+1] == nums[z] {
					z -= 1
				}
			} else if nums[x]+nums[y]+nums[z] < 0 {
				y += 1
				for y < z && nums[y-1] == nums[y] {
					y += 1
				}
			}
		}
	}
	return res
}

// @lc code=end

