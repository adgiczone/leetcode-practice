/*
 * @lc app=leetcode id=104 lang=golang
 *
 * [104] Maximum Depth of Binary Tree
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

func traverse(root *TreeNode, depth, res *int) {
	if root == nil {
		return
	}
	// 遍历前++
	(*depth)++
	traverse(root.Left, depth, res)
	// 记录一下深度
	if (*depth) > (*res) {
		(*res) = (*depth)
	}
	traverse(root.Right, depth, res)
	// 离开的时候深度--
	(*depth)--
	return
}

func maxDepth(root *TreeNode) int {
	var depth int = 0
	var res int = 0
	traverse(root, &depth, &res)
	return res
}

// @lc code=end
