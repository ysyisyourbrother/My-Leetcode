/*
 * @lc app=leetcode.cn id=347 lang=golang
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

type node struct {
	Key   int
	Value int
}

func topKFrequent(nums []int, k int) (res []int) {
	m := make(map[int]int)
	for _, num := range nums {
		m[num] += 1
	}
	nodes := make([]node, 0)
	for key, value := range m {
		nodes = append(nodes, node{key, value})
	}

	nodes = heapSort(nodes, len(nodes)-1, k)
	for i := 1; i <= k; i++ {
		res = append(res, nodes[len(nodes)-i].Key)
	}
	return
}

func maxHeap(nums []node, root, end int) []node {
	left := 2*root + 1
	right := 2*root + 2
	largest := root
	if left <= end && nums[left].Value > nums[largest].Value {
		largest = left
	}
	if right <= end && nums[right].Value > nums[largest].Value {
		largest = right
	}
	// 向下递归调整
	if largest != root {
		nums[root], nums[largest] = nums[largest], nums[root]
		nums = maxHeap(nums, largest, end)
	}
	return nums
}

func buildHeap(nums []node) []node {
	for i := len(nums) - 1; i >= 0; i-- {
		maxHeap(nums, i, len(nums)-1)
	}
	return nums
}

func heapSort(nums []node, end, k int) []node {
	// 将数组构建为最大堆
	nums = buildHeap(nums)
	for k > 0 {
		k -= 1
		// 交换头尾位置
		nums[0], nums[end] = nums[end], nums[0]
		end -= 1
		//恢复为最大堆
		nums = maxHeap(nums, 0, end)
	}
	return nums
}

// @lc code=end

