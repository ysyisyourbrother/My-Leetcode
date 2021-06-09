/*
 * @lc app=leetcode.cn id=23 lang=golang
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// go 通过接口形式提供了堆的实现，因此需要先实现接口
type ListNodes []*ListNode

func (l *ListNodes) Len() int {
	return len(*l)
}

func (l *ListNodes) Less(i, j int) bool {
	return (*l)[i].Val < (*l)[j].Val
}

func (l *ListNodes) Swap(i, j int) {
	(*l)[i], (*l)[j] = (*l)[j], (*l)[i]
}

func (l *ListNodes) Pop() interface{} {
	n := len(*l)
	x := (*l)[n-1]
	*l = (*l)[:n-1]
	return x
}

func (l *ListNodes) Push(x interface{}) {
	*l = append(*l, x.(*ListNode))
}

func mergeKLists(lists []*ListNode) *ListNode {
	listNodes := &ListNodes{}
	heap.Init(listNodes)
	for _, v := range lists {
		if v != nil {
			heap.Push(listNodes, v)
		}
	}
	head := &ListNode{} // 空链表头
	cur := head
	for listNodes.Len() > 0 {
		val := heap.Pop(listNodes).(*ListNode) // 栈顶推出元素
		cur.Next = val
		if val.Next != nil {
			heap.Push(listNodes, val.Next)
		}
		cur = cur.Next
	}
	return head.Next
}

// @lc code=end

