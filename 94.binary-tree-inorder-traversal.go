/*
 * @lc app=leetcode id=94 lang=golang
 * @lcpr version=30202
 *
 * [94] Binary Tree Inorder Traversal
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

func reverse(root *TreeNode, target *[]int) {
	if root == nil {
		return
	}
	reverse(root.Left, target)
	*target = append(*target, root.Val)
	reverse(root.Right, target)
}

func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	target := make([]int, 0)
	reverse(root, &target)
	return target
}

// @lc code=end

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

*/

