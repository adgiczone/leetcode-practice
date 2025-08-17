/*
 * @lc app=leetcode id=80 lang=golang
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
// 快慢指针again
func removeDuplicates(nums []int) int {
	duplicate := 0
	slow := 0
	for fast := 1; fast < len(nums); fast++ {
		// 如果相同,duplicate+1
		if nums[fast] == nums[slow] {
			duplicate++
			if duplicate <= 1 {
				// 重复两个以下的都不管
				slow++
				nums[slow] = nums[fast]
			}
		} else {
			slow++
			nums[slow] = nums[fast]
			duplicate = 0
		}
	}

	return slow + 1
}

// @lc code=end
