/*
 * @lc app=leetcode id=300 lang=golang
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// 动态规划， 主要是计算数组中的每一个元素前面递增的小于当前元素的个数
func lengthOfLIS(nums []int) int {
	// 初始化列表，用于计算数组中前面的每一个元素前面递增的小于当前元素的个数
	lessThanArray := make([]int, len(nums))
	max := func(x int, y int) int {
		if x > y {
			return x
		}
		return y
	}
	for i := range nums {
		// j遍历i之前所有的选项，确保所有可能的子序列都被考虑到
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				// 不能直接计算小于当前元素的值的个数，而是要计算之前连续小于当前数的值
				// 比如[2,5,3,7]中，要计算的是7前面的2,5或者2,3，而不是2,5,3
				// +1是因为要包括当前的值
				// 比较大小，得出目前最长子序列的值
				lessThanArray[i] = max(lessThanArray[i], lessThanArray[j]+1)
			}
		}
	}
	res := lessThanArray[0]
	for i := range lessThanArray {
		res = max(res, lessThanArray[i])
	}
	return res + 1
}

// @lc code=end
