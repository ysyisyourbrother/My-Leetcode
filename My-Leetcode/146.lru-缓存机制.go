/*
 * @lc app=leetcode.cn id=146 lang=golang
 *
 * [146] LRU 缓存机制
 */

// @lc code=start

type LRUCache struct {
	Size     int
	Capacity int
	Cache    map[int]*DLinkedNode
	Head     *DLinkedNode
	Tail     *DLinkedNode
}
type DLinkedNode struct {
	Key  int
	Val  int
	Next *DLinkedNode
	Last *DLinkedNode
}

func Constructor(capacity int) LRUCache {
	LRU := LRUCache{
		Size:     0,
		Capacity: capacity,
		Cache:    make(map[int]*DLinkedNode),
		Head:     &DLinkedNode{},
		Tail:     &DLinkedNode{},
	}
	LRU.Head.Next = LRU.Tail
	LRU.Head.Last = LRU.Tail
	LRU.Tail.Next = LRU.Head
	LRU.Tail.Last = LRU.Head

	return LRU
}

func (this *LRUCache) Get(key int) int {
	if v, ok := this.Cache[key]; ok {
		// 将节点移动到双向链表头
		this.moveToHead(v)
		return v.Val
	} else {
		return -1
	}

}

func (this *LRUCache) Put(key int, value int) {
	if v, ok := this.Cache[key]; ok {
		v.Val = value
		// 移到开头
		this.moveToHead(v)
		return
	} else { // 没找到元素 新插入
		// 容量满了，删掉末尾元素
		if this.Size == this.Capacity {
			// 扔掉双向链表尾部的变量并从map中删除
			delete(this.Cache, this.Tail.Last.Key)
			this.Tail.Last.Last.Next = this.Tail
			this.Tail.Last = this.Tail.Last.Last
			this.Size -= 1
		}

		// 容量没满，直接插入在双链表头
		newNode := &DLinkedNode{
			Key:  key,
			Val:  value,
			Last: this.Head,
			Next: this.Head.Next,
		}
		this.Size += 1
		this.Head.Next.Last = newNode
		this.Head.Next = newNode
		this.Cache[key] = newNode

	}
}

func (this *LRUCache) moveToHead(v *DLinkedNode) {
	// 将节点移动到双向链表头
	v.Last.Next = v.Next
	v.Next.Last = v.Last
	v.Last = this.Head
	v.Next = this.Head.Next
	this.Head.Next.Last = v
	this.Head.Next = v
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

