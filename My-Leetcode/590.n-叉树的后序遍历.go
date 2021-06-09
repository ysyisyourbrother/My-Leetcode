/*
 * @lc app=leetcode.cn id=590 lang=golang
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) []int {
	res := make([]int, 0)
	if root == nil {
		return res
	}
	for i := 0; i < len(root.Children); i++ {
		childRes := postorder(root.Children[i])
		res = append(res, childRes...)
	}
	res = append(res, root.Val)
	return res
}

// @lc code=end

