/*
 * @lc app=leetcode.cn id=236 lang=golang
 *
 * [236] 二叉树的最近公共祖先
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
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val == p.Val || root.Val == q.Val {
		return root
	} else {
		left := lowestCommonAncestor(root.Left, p, q)
		right := lowestCommonAncestor(root.Right, p, q)
		if left == nil {
			return right
		} else if right == nil {
			return left
		} else {
			return root
		}
	}
}

// @lc code=end

