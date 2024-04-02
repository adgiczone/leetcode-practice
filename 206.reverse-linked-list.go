/*
 * @lc app=leetcode id=206 lang=golang
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	// 一路堆栈下去，最后返回的last是最后一个元素，然后是倒数第二个。。。。
	last := reverseList(head.Next)
	// 但是传参的是head->Next，所以第一次跑到这里的head是倒数第二个元素， 然后是倒数第三个
	head.Next.Next = head
	// 斩断链表，下一次递归会重新连上新的元素
	head.Next = nil
	return last
}

// @lc code=end
