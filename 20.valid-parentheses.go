/*
 * @lc app=leetcode id=20 lang=golang
 *
 * [20] Valid Parentheses
 */

// @lc code=start
func isValid(s string) bool {
	leftfunc := func(c byte) byte {
		if c == ')' {
			return '('
		}
		if c == ']' {
			return '['
		}
		if c == '}' {
			return '{'
		}
		return 0
	}
	left_stack := make([]byte, 0)

	for i := 0; i < len(s); i++ {
		if s[i] == '(' || s[i] == '{' || s[i] == '[' {
			left_stack = append(left_stack, s[i])
		} else {
			if len(left_stack) != 0 && leftfunc(s[i]) == left_stack[len(left_stack)-1] {
				left_stack = left_stack[:len(left_stack)-1]
			} else {
				return false
			}
		}
	}
	return len(left_stack) == 0
}

// @lc code=end
