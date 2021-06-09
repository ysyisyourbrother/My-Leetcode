/*
 * @lc app=leetcode.cn id=725 lang=golang
 *
 * [725] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitListToParts(root *ListNode, k int) []*ListNode {
	cur := root
	count := 0
	for cur != nil {
		count += 1
		cur = cur.Next
	}
	num, remainder := count/k, count%k
	res := make([]*ListNode, 0)
	cur = root
	for i := 0; i < k; i++ {
		var width int
		// 确定这个part的节点数量
		if i < remainder {
			width = num + 1
		} else {
			width = num
		}
		res = append(res, cur)
		// cur 向前移动width个单位
		for width != 0 && cur != nil {
			if width == 1 {
				cur, cur.Next = cur.Next, nil
				break
			}
			width -= 1
			cur = cur.Next
		}
	}
	return res

}

// @lc code=end

