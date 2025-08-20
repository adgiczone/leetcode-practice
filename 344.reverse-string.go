/*
 * @lc app=leetcode.cn id=344 lang=golang
 * @lcpr version=30202
 *
 * [344] 反转字符串
 */

// @lc code=start
func reverseString(s []byte) {
	if len(s) <= 1 {
		return
	}
	length := len(s)
	for i := 0; i < length; i++ {
		if i >= (length - i - 1) {
			break
		}
		tmp := byte(s[i])
		s[i] = byte(s[length-1-i])
		s[length-1-i] = tmp
	}
}

// @lc code=end

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

*/

