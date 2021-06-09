/*
 * @lc app=leetcode.cn id=662 lang=golang
 *
 * [662] 二叉树最大宽度
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
type item struct {
	depth int
	index int
	node  *TreeNode
}

func widthOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}
	queue := []item{{0, 0, root}}
	var i, curDepth int = 0, 0
	var maxWidth, left int
	for i < len(queue) {
		if curDepth != queue[i].depth {
			if queue[i-1].index-left+1 > maxWidth {
				maxWidth = queue[i-1].index - left + 1
			}
			curDepth = queue[i].depth
			left = queue[i].index
		}
		if queue[i].node.Left != nil {
			queue = append(queue, item{queue[i].depth + 1, 2*queue[i].index + 1, queue[i].node.Left})
		}
		if queue[i].node.Right != nil {
			queue = append(queue, item{queue[i].depth + 1, 2*queue[i].index + 2, queue[i].node.Right})
		}
		i += 1
	}
	if queue[i-1].index-left+1 > maxWidth {
		maxWidth = queue[i-1].index - left + 1
	}
	return maxWidth
}

// @lc code=end

