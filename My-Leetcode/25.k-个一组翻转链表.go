/*
 * @lc app=leetcode.cn id=25 lang=golang
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}
	var res *ListNode = head
	var flag int = 0
	var last *ListNode // 上一组的最后一个节点
	ptr1, ptr2 := head, head
	for {
		counter := 0
		for counter < k && ptr2 != nil {
			ptr2 = ptr2.Next
			counter += 1
		}
		if counter < k {
			break
		}
		newHead := reverseNodes(ptr1, ptr2)
		if flag == 0 {
			res = newHead
			flag = 1
		}
		if last != nil {
			last.Next = newHead
		}
		ptr1.Next = ptr2
		last, ptr1 = ptr1, ptr2
	}
	return res
}

func reverseNodes(start, end *ListNode) *ListNode {
	if start.Next == end {
		return start
	}
	next := start.Next
	newHead := reverseNodes(next, end)
	next.Next = start
	start.Next = nil
	return newHead
}

func printNodes(start *ListNode) {
	for start != nil {
		start = start.Next
	}
	fmt.Println()
}

// @lc code=end

