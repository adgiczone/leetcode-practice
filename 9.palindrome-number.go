/*
 * @lc app=leetcode.cn id=9 lang=golang
 * @lcpr version=30202
 *
 * [9] 回文数
 */

// @lc code=start
func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	temp := x
	y := 0
	for temp > 0 {
		num := temp % 10
		temp = temp / 10
		y = y*10 + num
	}
	return y == x
}

// @lc code=end

/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

*/

