/*
 * @lc app=leetcode id=114 lang=golang
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// 把二叉树拉成链表，先拉左节点，然后拉右节点，然后把右节点连接到左节点的后面
func flatten(root *TreeNode) {
	if root == nil {
		return
	}
	flatten(root.Left)
	flatten(root.Right)
	// 获取左右子树
	left := root.Left
	right := root.Right
	// 把左子树链接到右子树上面
	root.Left = nil
	root.Right = left

	p := root
	// 循环到最后
	for p.Right != nil {
		p = p.Right
	}
	// 然后把右子树连接到左子树最后面
	p.Right = right
}

// @lc code=end
