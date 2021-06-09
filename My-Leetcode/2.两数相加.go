/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) (head *ListNode) {
	var value, carry int
	var x1, x2 int
	var tail *ListNode
	for l1 != nil || l2 != nil {
		if l1 == nil {
			x1 = 0
		} else {
			x1 = l1.Val
			l1 = l1.Next
		}
		if l2 == nil {
			x2 = 0
		} else {
			x2 = l2.Val
			l2 = l2.Next
		}
		value, carry = (x1+x2+carry)%10, (x1+x2+carry)/10
		fmt.Println(value)
		if head == nil {
			head = &ListNode{Val: value}
			tail = head
		} else {
			tail.Next = &ListNode{Val: value}
			tail = tail.Next
		}
	}
	if carry > 0 {
		tail.Next = &ListNode{Val: carry}
	}
	return
}

// @lc code=end
