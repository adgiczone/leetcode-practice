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

	length := 0
	for p := head; p != nil; p = p.Next {
		length++
	}
	if k >= length {
		k = k % length
	}
	if k == 0 {
		return head
	}

	dummy := &ListNode{-1, head}
	slow, fast := dummy, dummy
	start := 1

	for fast.Next != nil || start < k {
		if start > k {
			slow = slow.Next
		}
		start++
		fast = fast.Next
	}
	newHead := slow.Next
	slow.Next = nil
	fast.Next = head

	return newHead
}

// @lc code=end
