/*
 * @lc app=leetcode id=3 lang=golang
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
// 滑动窗口
func lengthOfLongestSubstring(s string) int {
	if s == "" {
		return 0
	}
	// 窗口
	window := make(map[byte]int, 0)
	// 左右边界
	left, right := 0, 0
	// 最大长度
	maxLength := 0
	// 左开右闭
	for right < len(s) {
		c := s[right]
		// 拉长窗口
		window[c]++
		right++
		// 如果有重复的元素进入，那么元素的个数就大于1了
		for window[c] > 1 {
			// 左边界的元素移出窗口
			window[s[left]]--
			// 窗口缩小到当前重复的元素离开
			left++
			// 注意这里要先减少窗口的个数，不然减去次数的字符不是被缩小的字符。
		}
		if right-left > maxLength {
			maxLength = right - left
		}
	}
	return maxLength
}

// @lc code=end

