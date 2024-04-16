/*
 * @lc app=leetcode id=116 lang=golang
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

// 把二叉树遍历变成三叉树遍历
func traverse(l *Node, r *Node) {
	if l == nil && r == nil {
		return
	}
	l.Next = r
	// 左分叉
	traverse(l.Left, l.Right)
	// 中分叉
	traverse(l.Right, r.Left)
	// 右分叉
	traverse(r.Left, r.Right)
}

func connect(root *Node) *Node {
	if root == nil {
		return root
	}
	root.Next = nil
	traverse(root.Left, root.Right)
	return root
}
// @lc code=end

