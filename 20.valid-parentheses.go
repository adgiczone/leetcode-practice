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

// 括号必须按{}，[], ()的顺序
func isValidPriority(s string) bool {
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
	// 加一个优先级
	getPriority := func(c byte) int {
		if c == ')' || c == '(' {
			return 0
		}
		if c == ']' || c == '[' {
			return 1
		}
		if c == '}' || c == '{' {
			return 2
		}
		return 0
	}
	curPriority := getPriority('{')
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
		fmt.Printf("cur priority %d input %d", curPriority, getPriority(s[i]))
		// 检查优先级， 如果当前优先级比较大就不管
		if getPriority(s[i]) < curPriority || getPriority(leftfunc(s[i])) >= curPriority {
			// 最后一个pass
			if (i + 1) >= len(s) {
				continue
			}
			// 右括号的优先级等于当前的优先级，获取下一个元素的优先级
			if getPriority(leftfunc(s[i])) == curPriority {
				curPriority = getPriority(s[i+1])
			} else {
				// 当前优先级小于之前的优先级，退出
				return false
			}
		}
	}
	return len(left_stack) == 0
}

// @lc code=end
