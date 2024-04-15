/*
 * @lc app=leetcode id=100 lang=golang
 *
 * [100] Same Tree
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
func isSameTree(p *TreeNode, q *TreeNode) bool {
    if p == nil && q == nil {
		return true
	}
	// 前面已经判断过都为nil的情况了
	if p == nil || q == nil {
		return false
	}
	// 判断值是否正确
	if p.Val != q.Val {
		return false
	}
	// 接着遍历右子树和左子树
	return isSameTree(p.Right, q.Right) && isSameTree(p.Left, q.Left)
}
// @lc code=end

