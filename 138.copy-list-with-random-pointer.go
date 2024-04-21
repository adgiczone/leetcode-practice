/*
 * @lc app=leetcode id=138 lang=golang
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

// 简单来说就是要构造一个和传入的链表一模一样的链表。新链表的Next指向新链表的Next，
// Random指向新链表的Random
func copyRandomList(head *Node) *Node {
	// 构造一个hash表
	copyNode := make(map[*Node]*Node)
	// 把旧链表的值填到hash表里面去。因为是遍历，所以不会重复
	for p := head; p != nil; p = p.Next {
		copyNode[p] = &Node{
			Val: p.Val,
		}
	}
	// 根据旧链表的值构造新的链表
	for p := head; p != nil; p = p.Next {
		if p.Next != nil {
			// 不能直接指向旧链表，这样不符合规则，所以要用到hash表
			copyNode[p].Next = copyNode[p.Next]
		}
		if p.Random != nil {
			copyNode[p].Random = copyNode[p.Random]
		}
	}
	return copyNode[head]
}

// @lc code=end
