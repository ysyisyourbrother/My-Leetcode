/*
 * @lc app=leetcode.cn id=235 lang=golang
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	var getPath = func(root, p *TreeNode) []*TreeNode {
		res := []*TreeNode{}
		for {
			res = append(res, root)
			if root.Val == p.Val {
				break
			} else if root.Val > p.Val {
				root = root.Left
			} else {
				root = root.Right
			}
		}
		return res
	}

	path1 := getPath(root, p)
	path2 := getPath(root, q)
	var i int = 0
	for i < len(path1) && i < len(path2) {
		if path1[i].Val == path2[i].Val {
			i += 1
		} else {
			break
		}
	}
	return path1[i-1]

}

// @lc code=end

