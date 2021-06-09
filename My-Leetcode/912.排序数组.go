/*
 * @lc app=leetcode.cn id=912 lang=golang
 *
 * [912] 排序数组
 */

// @lc code=start
func sortArray(nums []int) []int {
	nums = heapSort(nums)
	return nums
}

// 插入排序
func insertSort(nums []int) []int {
	for i := 1; i < len(nums); i++ {
		cur := nums[i]
		j := i - 1
		for j >= 0 && nums[j] > cur {
			nums[j+1] = nums[j]
			j -= 1
		}
		nums[j+1] = cur
	}
	return nums
}

// 冒泡排序
func bubbleSort(nums []int) []int {
	for i := 0; i < len(nums)-1; i++ {
		for j := 0; j < len(nums)-1-i; j++ {
			if nums[j] > nums[j+1] {
				nums[j], nums[j+1] = nums[j+1], nums[j]
			}
		}
	}
	return nums
}

// 快速排序
func quickSort(nums []int, l, r int) []int {
	if l >= r {
		return nums
	}
	i, j := l, r
	cur := nums[l]
	for i < j {
		for i < j && nums[j] >= cur {
			j -= 1
		}
		if i < j {
			nums[i] = nums[j]
			i += 1
		}
		for i < j && nums[i] < cur {
			i += 1
		}
		if i < j {
			nums[j] = nums[i]
			j -= 1
		}
	}
	nums[i] = cur
	quickSort(nums, l, i-1)
	quickSort(nums, i+1, r)
	return nums
}

// 归并排序
func mergeSort(nums []int, low, high int) []int {
	if low >= high {
		return nums
	}
	mid := (low + high) / 2
	// 递归
	nums1 := mergeSort(nums, low, mid)
	nums2 := mergeSort(nums, mid+1, high)
	// 归并数组
	tmp := make([]int, 0)
	i, j := low, mid+1
	for i <= mid && j <= high {
		if nums1[i] <= nums2[j] {
			tmp = append(tmp, nums1[i])
			i += 1
		} else {
			tmp = append(tmp, nums2[j])
			j += 1
		}
	}
	if i == mid+1 {
		for ; j <= high; j++ {
			tmp = append(tmp, nums2[j])
		}
	} else {
		for ; i <= mid; i++ {
			tmp = append(tmp, nums1[i])
		}
	}
	for a := 0; a < len(tmp); a++ {
		nums[a+low] = tmp[a]
	}
	return nums
}

// 堆排序
func heapSort(nums []int) []int {
	// 构建最大堆
	var maxHeap func(nums []int, start, end int) []int
	maxHeap = func(nums []int, start, end int) []int {
		lagest := start
		if 2*start+1 <= end && nums[2*start+1] > nums[lagest] {
			lagest = 2*start + 1
		}
		if 2*start+2 <= end && nums[2*start+2] > nums[lagest] {
			lagest = 2*start + 2
		}
		// 递归修正最大堆
		if lagest != start {
			nums[start], nums[lagest] = nums[lagest], nums[start]
			nums = maxHeap(nums, lagest, end)
		}
		return nums
	}
	var i int
	// 将数组初始化为最大堆
	for i = len(nums)/2 - 1; i >= 0; i-- {
		nums = maxHeap(nums, i, len(nums)-1)
	}
	// 将堆顶移到末尾并修正最大堆
	for i := len(nums) - 1; i >= 1; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		nums = maxHeap(nums, 0, i-1)
	}
	return nums
}

// @lc code=end

