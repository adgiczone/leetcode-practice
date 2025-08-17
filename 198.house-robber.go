/*
 * @lc app=leetcode id=198 lang=golang
 *
 * [198] House Robber
 */

// @lc code=start
// 动态规划
func max(x int, y int) int {
	if x > y {
		return x
	}
	return y
}

func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]	
	}
	
	// 先分子问题: 抢倒数第一家和抢倒数第二家
	// dp用来存储在每间房之前总共能偷的最大的金额, 累计的最优解
	dp := make([]int, len(nums))
	// 偷了第一间房子的
	dp[0] = nums[0]
	// 边界问题, 如果只有两间房的话
	dp[1] = max(nums[1], nums[0])
	

	for i := 2; i < len(nums); i++ {
		// 如果之前那间房钱多, 就放弃当前这间房, 否则偷这间房
		dp[i] = max(dp[i-1], dp[i-2]+nums[i])
	}
	return dp[len(nums)-1]
}

// @lc code=end
