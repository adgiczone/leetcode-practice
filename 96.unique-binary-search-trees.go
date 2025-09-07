/*
 * @lc app=leetcode id=96 lang=golang
 * @lcpr version=30202
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
// n 是节点数
func numTrees(n int) int {
	if n <= 0 {
		return 0
	}
	// n个节点, 所以dp是n+1个
	dp := make([]int, n+1)
	// corner case, 0个节点是空树
	dp[0] = 1
	// 1个节点也就只有一个root
	dp[1] = 1
	// 前面corner case已经完成了, 从第二个节点开始
	for i := 2; i <= n; i++ {
		// 计算到当前节点的数目
		for j := 1; j <= i; j++ {
			// dp[i] += 是因为要包括之前dp的方案, 而不是只算当前dp的方案
			// 相乘是左子树和右子树所有可能的值的合并.
			dp[i] += dp[j-1] * dp[i-j]
		}
	}
	return dp[n]

}

// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

*/

