/*
 * @lc app=leetcode.cn id=19 lang=golang
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	nullHead := &ListNode{}
	node := nullHead
	node.Next = head

	ptr := head
	for n > 0 {
		n -= 1
		ptr = ptr.Next
	}
	for ptr != nil {
		ptr = ptr.Next
		node = node.Next
	}
	node.Next = node.Next.Next
	return nullHead.Next
}

// @lc code=end

