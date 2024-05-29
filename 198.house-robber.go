/*
 * @lc app=leetcode id=198 lang=golang
 *
 * [198] House Robber
 */

// @lc code=start
// 动态规划
func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	res := 0
	var dp func(start int) int
	dp = func(start int) int {
		if start >= len(nums) {
			return 0
		}
		res = dp
	}
	return res
}

// @lc code=end
