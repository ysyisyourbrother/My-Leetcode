/*
 * @lc app=leetcode.cn id=107 lang=golang
 *
 * [107] 二叉树的层序遍历 II
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
type Node struct {
	Ptr   *TreeNode
	Depth int
}

func levelOrderBottom(root *TreeNode) [][]int {
	res := make([][]int, 0)
	if root == nil {
		return res
	}
	queue := make([]Node, 0)
	queue = append(queue, Node{root, 0})
	curLevelNodes := make([]int, 0)
	curDepth, index := 0, 0
	for index < len(queue) {
		cur := queue[index]
		if curDepth != cur.Depth {
			curDepth = cur.Depth
			res = append(res, curLevelNodes)
			curLevelNodes = make([]int, 0)
		}
		curLevelNodes = append(curLevelNodes, cur.Ptr.Val)

		if cur.Ptr.Left != nil {
			queue = append(queue, Node{cur.Ptr.Left, cur.Depth + 1})
		}
		if cur.Ptr.Right != nil {
			queue = append(queue, Node{cur.Ptr.Right, cur.Depth + 1})
		}
		index += 1
	}
	res = append(res, curLevelNodes)

	for i := 0; i <= len(res)/2-1; i++ {
		res[i], res[len(res)-i-1] = res[len(res)-i-1], res[i]
	}
	return res
}

// @lc code=end

