/*
 * @lc app=leetcode.cn id=695 lang=golang
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
type node struct {
	i, j int
}

func maxAreaOfIsland(grid [][]int) int {
	bfs := func(grid [][]int, start node) int {
		var res, index int = 0, 0
		queue := make([]node, 0)
		queue = append(queue, node{start.i, start.j})
		grid[start.i][start.j] = 0
		for index < len(queue) {
			curNode := queue[index]
			i, j := curNode.i, curNode.j
			res, index = res+1, index+1

			if i-1 >= 0 && grid[i-1][j] == 1 {
				queue = append(queue, node{i - 1, j})
				grid[i-1][j] = 0
			}
			if i+1 < len(grid) && grid[i+1][j] == 1 {
				queue = append(queue, node{i + 1, j})
				grid[i+1][j] = 0
			}
			if j-1 >= 0 && grid[i][j-1] == 1 {
				queue = append(queue, node{i, j - 1})
				grid[i][j-1] = 0
			}
			if j+1 < len(grid[0]) && grid[i][j+1] == 1 {
				queue = append(queue, node{i, j + 1})
				grid[i][j+1] = 0
			}
		}
		return res
	}
	maxArea := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 1 {
				area := bfs(grid, node{i, j})
				if area > maxArea {
					maxArea = area
				}
			}
		}
	}
	return maxArea
}

// @lc code=end

