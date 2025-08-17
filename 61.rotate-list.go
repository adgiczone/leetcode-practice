/*
 * @lc app=leetcode id=61 lang=golang
 *
 * [61] Rotate List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 这种情况k很大的时候就会遍历多次，时间用的太多了
// func rotateRight(head *ListNode, k int) *ListNode {
// 	if head == nil || k == 0 {
// 		return head
// 	}
// 	dummy := &ListNode{-1, head}
// 	slow, fast := dummy, head
// 	start := 1

// 	for fast.Next != nil || start < k {
// 		if start > k-1 {
// 			slow = slow.Next
// 		}
// 		if fast.Next == nil {
// 			fast = head
// 			start++
// 			continue
// 		}
// 		start++
// 		fast = fast.Next
// 	}
// 	newHead := slow.Next
// 	slow.Next = nil
// 	if start != k {
// 		fast.Next = head
// 	}

// 	return newHead
// }

// O(2n),通过取余的方式把k降到长度一下
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	// 计算长度
	length := 0
	for p := head; p != nil; p = p.Next {
		length++
	}
	// 如果k比length长, 就取余
	if k >= length {
		k = k % length
	}
	if k == 0 {
		// 取余之后发现是不需要旋转
		return head
	}

	dummy := &ListNode{-1, head}
	slow, fast := dummy, dummy
	start := 1

	for fast.Next != nil || start < k {
		// 走到需要旋转的节点的下一个,slow开始走
		if start > k {
			slow = slow.Next
		}
		start++
		fast = fast.Next
	}
	// slow的下一个作为头
	newHead := slow.Next
	slow.Next = nil
	// 拼接原本的链表头
	fast.Next = head

	return newHead
}

// @lc code=end
