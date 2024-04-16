/*
 * @lc app=leetcode id=543 lang=golang
 *
 * [543] Diameter of Binary Tree
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

func depth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	// 获取左边节点的深度
	left := depth(root.Left)
	max := left
	// 获取右边节点的深度
	right := depth(root.Right)
	// 比较一下
	if right > max {
		max = right
	}
	// 返回最大的深度+自己节点
	return max + 1
}

func traverse(node *TreeNode, maxDiameter *int) {
	if node == nil {
		return
	}
	right := depth(node.Right)
	left := depth(node.Left)
	// 计算直径，然后和最大直径比较
	if (left + right ) > *maxDiameter {
		*maxDiameter = (left + right)
	}
	// 接下来遍历每个节点计算每个节点的直径
	traverse(node.Left, maxDiameter)
	traverse(node.Right, maxDiameter)
}

func diameterOfBinaryTree(root *TreeNode) int {
	maxDiameter := 0
	traverse(root, &maxDiameter)
	return maxDiameter
}

// @lc code=end
