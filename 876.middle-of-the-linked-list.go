/*
 * @lc app=leetcode id=876 lang=golang
 *
 * [876] Middle of the Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
	// 还是快慢指针
	fast := head
	slow := head
	// 快指针走的比慢指针快一倍
	// 最后快指针为空的时候，慢指针一定在中间
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}
	return slow
}

// @lc code=end
