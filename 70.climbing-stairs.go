/*
 * @lc app=leetcode id=70 lang=golang
 *
 * [70] Climbing Stairs
 */

// @lc code=start
// 动态规划
func climbStairs(n int) int {
	//　最小子问题，跳过
	if n == 1 || n == 2 {
		return n
	}
	// 构建dp table
	dp := make([]int, n+1)
	// 找到最小子问题
	dp[1] = 1
	dp[2] = 2
	// 子问题叠加找到答案
	for i := 3; i < n+1; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}
	return dp[n]
}

// @lc code=end
