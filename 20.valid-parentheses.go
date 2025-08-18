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
			//堆栈
			left_stack = append(left_stack, s[i])
		} else {
			// 找到前一个栈的元素一定要符合顺序.
			if len(left_stack) != 0 && leftfunc(s[i]) == left_stack[len(left_stack)-1] {
				left_stack = left_stack[:len(left_stack)-1]
			} else {
				return false
			}
		}
	}
	return len(left_stack) == 0
}

// 括号必须按{}，[], ()的顺序
func isValid(s string) bool {
	stack := []rune{}
	// Map for bracket pairs
	pairs := map[rune]rune{
		')': '(',
		']': '[',
		'}': '{',
	}

	// Order for priority validation
	priority := map[rune]int{
		'{': 1,
		'[': 2,
		'(': 3,
	}

	for _, ch := range s {
		switch ch {
		case '(', '[', '{':
			// Check nested priority: disallow if nesting breaks rule
			if len(stack) > 0 && priority[ch] <= priority[stack[len(stack)-1]] {
				return false
			}
			stack = append(stack, ch)
		case ')', ']', '}':
			if len(stack) == 0 || stack[len(stack)-1] != pairs[ch] {
				return false
			}
			stack = stack[:len(stack)-1]
		default:
			return false // invalid character
		}
	}

	return len(stack) == 0
}

// @lc code=end
