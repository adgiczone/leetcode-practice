/*
 * @lc app=leetcode id=203 lang=golang
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	// 还是快慢指针
	dummy := &ListNode{Next: head}

	slow := dummy
	fast := head

	for fast != nil {
		// 遇到指定元素，慢指针的下一个等于快指针的下一个
		// 跳过指定元素的列表
		if fast.Val == val {
			slow.Next = fast.Next
		} else {
			// 否则慢指针=快指针
			slow = fast
		}
		fast = fast.Next
	}
	return dummy.Next
}

// @lc code=end
