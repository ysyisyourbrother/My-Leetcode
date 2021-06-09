/*
 * @lc app=leetcode.cn id=239 lang=golang
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
func maxSlidingWindow(nums []int, k int) []int {
	res := make([]int, len(nums)-k+1)
	queue := make(monoQueue, 0)

	i := 0
	for i = 0; i < k; i++ {
		queue = queue.enqueue(pair{nums[i], i})
	}
	res[0] = queue[0].num

	for j := 1; i < len(nums); i, j = i+1, j+1 {
		// j 指向滑动窗口当前第一个，i指向滑动窗口的下一个
		// 滑动窗口加入新元素
		queue = queue.enqueue(pair{nums[i], i})
		// 如果队列头不是新元素，将它移除
		if queue[0].index == j-1 {
			queue = queue.dequeue()
		}
		res[j] = queue[0].num
	}

	return res
}

type monoQueue []pair
type pair struct {
	num   int
	index int
}

// 入队 把小于当前元素的都挤掉
func (queue monoQueue) enqueue(elem pair) monoQueue {
	i := 0
	for i = len(queue) - 1; i >= 0; i-- { //找到插入位置
		if queue[i].num > elem.num {
			break
		}
	}
	queue = queue[:i+1]
	return append(queue, elem)
}

//出队，去掉队首元素
func (queue monoQueue) dequeue() monoQueue {
	return queue[1:]
}

// @lc code=end

