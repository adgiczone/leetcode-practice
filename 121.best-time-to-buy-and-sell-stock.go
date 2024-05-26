/*
 * @lc app=leetcode id=121 lang=golang
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
func maxProfit(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}
	// 这个时间太长了
	// dpTables := make([]int, len(prices))
	// dpTables[0] = 0
	// max := 0
	// for i := 0; i < len(prices); i++ {
	// 	curProfit := 0
	// 	for j := 0; j < i; j++ {
	// 		if prices[i]-prices[j] > curProfit {
	// 			curProfit = prices[i] - prices[j]
	// 		}
	// 	}
	// 	if curProfit > max {
	// 		max = curProfit
	// 	}
	// }
	// return max
	// prices本身就可以是dpTable了，直接获取所有天数的最小消费，对比利润（当天消费-最小消费）
	// 预设最小消费
	minCost := math.MaxInt32
	// 预设最大利润
	maxProfit := 0

	for _, cost := range prices {
		if cost-minCost > 0 && cost-minCost > maxProfit {
			maxProfit = cost - minCost
		}

		if cost < minCost {
			minCost = cost
		}

	}
	return maxProfit
}

// @lc code=end
