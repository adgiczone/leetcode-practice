/*
 * @lc app=leetcode id=21 lang=golang
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	res := &ListNode{-1, nil}
	p := res
	l1 := list1
	l2 := list2
	// 两个链表同时走
	for l1 != nil && l2 != nil {
		// list1的值比较小就放在res当中
		if l1.Val < l2.Val {
			p.Next = l1
			l1 = l1.Next
		} else {
			// list2的值比较小就放在res当中
			p.Next = l2
			l2 = l2.Next
		}
		// 空list往后走
		p = p.Next
	}
	// 如果两个list的长度不一样，合并剩下的list
	if l1 != nil {
		p.Next = l1
	}
	if l2 != nil {
		p.Next = l2
	}
	return res.Next
}

// @lc code=end
