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
	small := &ListNode{-1, nil}
	// 存放大于x的链表，不能和small共用一个，会被覆盖
	large := &ListNode{-1, nil}
	s, l := small, large

	for h := head; h != nil; h = h.Next {
		if h.Val < x {
			s.Next = h
			s = s.Next
		} else {
			l.Next = h
			l = l.Next
		}
	}
	// 为了防止合并的时候large的末尾同时指向旧链表的其他节点
	// large末尾置空
	l.Next = nil
	// 连接两个链表
	s.Next = large.Next
	return small.Next
}

// @lc code=end
