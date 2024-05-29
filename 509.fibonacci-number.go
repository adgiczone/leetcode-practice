/*
 * @lc app=leetcode id=509 lang=golang
 *
 * [509] Fibonacci Number
 */

// @lc code=start
func fib(n int) int {
	if n == 0 {
		return 0
	}
	dp := make([]int, n+1)
	// base case
	dp[0] = 0
	dp[1] = 1
	if n < 2 {
		return dp[n]
	}
	//状态转移方程
	for i := 2; i <= n; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}
	return dp[n]
}

// @lc code=end
