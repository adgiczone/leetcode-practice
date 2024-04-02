/*
 * @lc app=leetcode id=169 lang=golang
 *
 * [169] Majority Element
 */

// @lc code=start
// 因为题目说主要元素一定过半
// 那就把不等于主要元素的数值看作负值，等于主要元素的看作正值，相加最后一定会大于0
func majorityElement(nums []int) int {
	target := 0
	count := 0
	for i := 0; i < len(nums); i++ {
		// 如果count为0，就把当前元素看作是主要元素
		if count == 0 {
			target = nums[i]
		}
		// 等于当前元素的+1
		if target == nums[i] {
			count++
		} else {
			// 不等于当前元素的-1
			count--
		}
	}
	// 返回当前元素
	return target
}

// @lc code=end
