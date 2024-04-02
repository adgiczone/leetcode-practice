/*
 * @lc app=leetcode id=19 lang=golang
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	// 加一个dummy防止出现只有一个元素的链表删除导致无效的问题
	h1 := &ListNode{-1, head}
	// 快慢指针
	fast, slow := h1, h1
	i := 0
	for fast != nil {
		// 快指针先走，过了节点n的时候慢指针跟上
		if i > n {
			slow = slow.Next
		}
		fast = fast.Next
		i++
	}
	// 快指针到底的时候，慢指针下一个节点是n
	slow.Next = slow.Next.Next
	return h1.Next
}

// @lc code=end
