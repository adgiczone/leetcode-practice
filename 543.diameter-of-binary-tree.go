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

func traverse(root *TreeNode, depth, res *int) {
	if root == nil {
		return
	}
	(*depth)++
	fmt.Println("++++++++", (*depth), root.Val)
	traverse(root.Left, depth, res)
	if (*depth) > (*res) {
		(*res) = (*depth)
	}
	traverse(root.Right, depth, res)
	fmt.Println("--------", (*depth), root.Val)
	(*depth)--
}

func diameterOfBinaryTree(root *TreeNode) int {
	depth, leftRes, rightRes := 0, 0, 0
	traverse(root.Left, &depth, &leftRes)
	fmt.Println("left", leftRes)
	// if leftRes != 0 {
	// 	leftRes++
	// }
	depth = 0
	traverse(root.Right, &depth, &rightRes)
	fmt.Println("right", rightRes)
	// if rightRes != 0 {
	// 	rightRes++
	// }
	return leftRes + rightRes
}

// @lc code=end
