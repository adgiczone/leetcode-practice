/*
 * @lc app=leetcode id=25 lang=golang
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseRegion(start, end *ListNode) *ListNode {
	var head *ListNode
	cur := start
	for cur != end {
		nxt := cur.Next
		cur.Next = head
		head = cur
		cur = nxt
	}
	return head
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	start, end := head, head
	// 找出k区域内的节点, 区域是[start, end)
	for n := 0; n < k; n++ {
		if end == nil {
			return head
		}
		end = end.Next
	}
	// 循环结束时end本身已经指向下一个需要反转的节点了
	// 返回的newHead是反转过后的最新的开始节点
	newHead := reverseRegion(start, end)
	// start在这里是反转的链表结尾, 把start和下一个开始节点连接起来.
	start.Next = reverseKGroup(end, k)
	return newHead
}

// @lc code=end
