/*
 * @lc app=leetcode id=198 lang=golang
 *
 * [198] House Robber
 */

// @lc code=start
func rob(nums []int) int {
	res := nums[0]
	max := func(x int, y int) int {
		if x > y {
			return x
		}
		return y
	}
	if len(nums) == 2 {
		return max(nums[0], nums[1])
	}

	for i := range nums {
		if i-2 < 0 {
			res = nums[i]
			continue
		}
		nums[i] = nums[i] + nums[i-2]
		fmt.Println("_+_+", res, nums[i])
		res = max(nums[i], res)

	}

	return res
}

// @lc code=end
