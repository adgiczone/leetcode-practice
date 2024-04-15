/*
 * @lc app=leetcode id=101 lang=golang
 *
 * [101] Symmetric Tree
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

func isSame(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}

	if p == nil || q == nil {
		return false
	}
	if p.Val != q.Val {
		return false 
	}
	return isSame(p.Left, q.Right) && isSame(p.Right, q.Left)
}

func isSymmetric(root *TreeNode) bool {
	// 对称性看的是左右节点是否相同
	return isSame(root.Left, root.Right)
}
// @lc code=end

