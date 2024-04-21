/*
 * @lc app=leetcode id=92 lang=golang
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// left 和 right 是位置
var next *ListNode

func reverse(root *ListNode, num int, right int) *ListNode {
	if root == nil {
		return root
	}
	if num == right {
		// next是原本链表的后面节点
		next = root.Next
		return root
	}
	// right 一定在left后面
	last := reverse(root.Next, num+1, right)
	root.Next.Next = root
	// 之前的链表反转这里置为0是因为最后一个元素后面是nil
	// 现在改成原本链表的下一个元素
	root.Next = next
	return last
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	dummy := &ListNode{
		Val:  -1,
		Next: head,
	}
	p := dummy
	num := 0
	for p != nil {
		// 当前节点是left的前一位的时候，开始准备反转
		if num == left-1 {
			last := reverse(p.Next, num+1, right)
			// 把当前节点的下一个换成反转之后的节点
			p.Next = last
			// 反转已完成，退出循环
			break
		}
		num++
		p = p.Next
	}
	return dummy.Next
}

// @lc code=end
