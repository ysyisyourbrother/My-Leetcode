/*
 * @lc app=leetcode.cn id=222 lang=golang
 *
 * [222] 完全二叉树的节点个数
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
func countNodes(root *TreeNode) int {
	countLevel := func(root *TreeNode) int {
		level := 0
		for root != nil {
			root = root.Left
			level += 1
		}
		return level
	}
	if root == nil {
		return 0
	}
	leftLevel := countLevel(root.Left)
	rightLevel := countLevel(root.Right)
	// 如果左深度等于右深度，则左一定为满二叉树
	if leftLevel == rightLevel {
		return countNodes(root.Right) + (1<<leftLevel - 1) + 1
	} else {
		return countNodes(root.Left) + (1<<rightLevel - 1) + 1
	}
}

// @lc code=end

