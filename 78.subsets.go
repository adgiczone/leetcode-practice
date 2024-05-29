/*
 * @lc app=leetcode id=78 lang=golang
 *
 * [78] Subsets
 */

// @lc code=start
// 经典回溯算法
func subsets(nums []int) [][]int {
	res := make([][]int, 0)
	track := make([]int, 0)

	var backtrack func(start int)
	backtrack = func(start int) {
		// 扩展结果, 放在最前面是因为要把[]算上去
		tmp := make([]int, len(track))
		copy(tmp, track)
		res = append(res, tmp)

		for i := start; i < len(nums); i++ {
			// 扩展数组
			track = append(track, nums[i])
			// 选择下一个
			backtrack(i + 1)
			// 已经选择过了，清空选择
			track = track[:len(track)-1]
		}
	}
	backtrack(0)
	return res
}

// @lc code=end

