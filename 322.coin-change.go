/*
 * @lc app=leetcode id=322 lang=golang
 *
 * [322] Coin Change
 */

// @lc code=start
// 动态规划
func coinChange(coins []int, amount int) int {
	// 预先申请需要的硬币数量，因为不管怎么都不会超过amount的值
	// 所以amount+1就好
	dpTable := make([]int, amount+1)
	// range返回的是一个副本，无法赋值
	for i := range dpTable {
		// 预设一个很大的值
		dpTable[i] = math.MaxInt32
	}

	min := func(x int, y int) int {
		if x < y {
			return x
		}
		return y
	}
	// 基础值
	dpTable[0] = 0
	for i := range dpTable {
		for _, coin := range coins {
			// 子问题不存在，跳过
			if i-coin < 0 {
				continue
			}
			//当前值和子问题的值作比较
			// +1 是因为上一个子问题的答案不会包括现在的问题的硬币数量
			dpTable[i] = min(dpTable[i], dpTable[i-coin]+1)
		}
	}

	// 初始值，不管
	if dpTable[amount] == math.MaxInt32 {
		return -1
	}
	return dpTable[amount]
}

// @lc code=end
