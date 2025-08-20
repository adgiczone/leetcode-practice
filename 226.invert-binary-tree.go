/*
 * @lc app=leetcode id=226 lang=golang
 *
 * [226] Invert Binary Tree
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
// 翻转二叉树
func traverse(root *TreeNode) {
	if root == nil {
		return
	}
	// 后序遍历和前序遍历都可以
	traverse(root.Left)
	traverse(root.Right)
	// 交换左右节点
	tmp := root.Left
	root.Left = root.Right
	root.Right = tmp
}

func invertTree(root *TreeNode) *TreeNode {
	traverse(root)
	return root
}

// @lc code=end

