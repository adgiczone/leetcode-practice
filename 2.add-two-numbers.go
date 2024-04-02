/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	p1 := l1
	p2 := l2
	h3 := &ListNode{-1, nil}
	p3 := h3
	carry := 0

	for p1 != nil && p2 != nil {
		sum := p1.Val + p2.Val + carry
		if sum >= 10 {
			sum, carry = sum-10, 1
		} else {
			carry = 0
		}
		p3.Next = &ListNode{sum, nil}
		p1 = p1.Next
		p2 = p2.Next
		p3 = p3.Next
	}
	for p1 != nil {
		sum := p1.Val + carry
		if sum >= 10 {
			sum, carry = sum-10, 1
		} else {
			carry = 0
		}
		p3.Next = &ListNode{sum, nil}
		p1 = p1.Next
		p3 = p3.Next

	}
	for p2 != nil {
		sum := p2.Val + carry
		if sum >= 10 {
			sum, carry = sum-10, 1
		} else {
			carry = 0
		}
		p3.Next = &ListNode{sum, nil}
		p2 = p2.Next
		p3 = p3.Next
	}
	if carry != 0 {
		p3.Next = &ListNode{carry, nil}
	}
	return h3.Next
}

// @lc code=end
