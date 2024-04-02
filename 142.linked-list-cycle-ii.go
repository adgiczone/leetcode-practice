/*
 * @lc app=leetcode id=142 lang=golang
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
	// 还是快慢指针
	// slow一步，fast走两步，因为是整数倍，所以如果是环的话就会相遇，相遇的时候任意一个回到起点同步走，再次相遇就是环的起点
}

// @lc code=end
