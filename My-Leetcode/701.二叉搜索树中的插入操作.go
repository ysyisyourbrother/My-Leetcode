/*
 * @lc app=leetcode.cn id=701 lang=golang
 *
 * [701] 二叉搜索树中的插入操作
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
func insertIntoBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return &TreeNode{val, nil, nil}
	}
	ret := root
	for root != nil {
		if root.Val > val {
			if root.Left == nil {
				root.Left = &TreeNode{val, nil, nil}
				return ret
			} else {
				root = root.Left
			}
		} else {
			if root.Right == nil {
				root.Right = &TreeNode{val, nil, nil}
				return ret
			} else {
				root = root.Right
			}
		}
	}
	return ret
}

// @lc code=end

