/*
 * @lc app=leetcode.cn id=103 lang=golang
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}
	ret := make([][]int, 0)
	queue := make([]*TreeNode, 0)
	queue = append(queue, root)
	count := 0
	for len(queue) > 0 {
		res := make([]int, 0)
		tmp := make([]*TreeNode, 0)
		for i := 0; i < len(queue); i++ {
			res = append(res, queue[i].Val)
			if queue[i].Left != nil {
				tmp = append(tmp, queue[i].Left)
			}
			if queue[i].Right != nil {
				tmp = append(tmp, queue[i].Right)
			}
		}
		if count%2 == 1 {
			res = reverseSlice(res)
		}
		count += 1
		ret = append(ret, res)
		queue = tmp
	}
	return ret
}

func reverseSlice(s []int) []int {
	for i := 0; i < len(s)/2; i++ {
		s[i], s[len(s)-i-1] = s[len(s)-i-1], s[i]
	}
	return s
}

// @lc code=end

