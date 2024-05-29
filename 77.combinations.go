/*
 * @lc app=leetcode id=77 lang=golang
 *
 * [77] Combinations
 */

// @lc code=start
// 回溯算法
func combine(n int, k int) [][]int {
	res := make([][]int, 0)
	track := make([]int, 0)
	if n == 0 {
		return res
	}
	var backtrack func(start int, length int)

	backtrack = func(start int, length int) {
		for i := start; i < n; i++ {
			track = append(track, i+1)
			if len(track) == length {
				tmp := make([]int, length)
				copy(tmp, track)
				res = append(res, tmp)
			}
			backtrack(i+1, k)
			track = track[:len(track)-1]
		}
	}
	backtrack(0, k)
	return res
}

// @lc code=end

