/*
 * @lc app=leetcode id=86 lang=golang
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	// 存放小于x的链表
	dummy1 := &ListNode{-1, nil}
	// 存放大于x的链表
	dummy2 := &ListNode{-1, nil}
	d1, d2, h1 := dummy1, dummy2, head

	for h1 != nil {
		if h1.Val < x {
			d1.Next = h1
			d1 = d1.Next
		} else {
			d2.Next = h1
			d2 = d2.Next
		}
		// 为了防止合并的时候d1的next同时指向h1和dummy2的头从而变成一个环，断开旧链表。
		temp := h1.Next
		h1.Next = nil
		h1 = temp
	}
	// 连接两个链表
	d1.Next = dummy2.Next
	return dummy1.Next
}

// @lc code=end
