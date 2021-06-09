package main

import (
	"fmt"
)

func twoSum(nums []int, target int) (res []int) {
	mymap := make(map[int]int)
	for index, i := range nums {
		if _, ok := mymap[target-i]; ok {
			return append(res, index, mymap[target-i])
		}
		mymap[i] = index
	}
	return
}

func main() {
	var nums = []int{3, 2, 4}
	target := 6
	res := twoSum(nums, target)
	fmt.Println(res)
}
