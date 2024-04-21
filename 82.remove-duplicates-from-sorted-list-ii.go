/*
 * @lc app=leetcode id=82 lang=golang
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// func deleteDuplicates(head *ListNode) *ListNode {
// 	hash := make(map[int]*ListNode)
// 	dupVal := math.MaxInt32

// 	for h := head; h != nil; h = h.Next {
// 		if h.Val == dupVal {
// 			continue
// 		}
// 		hash[h.Val] = h
// 		if h.Next != nil && h.Val == h.Next.Val {
// 			dupVal = h.Val
// 			delete(hash, dupVal)
// 		}
// 	}

// 	// go的hash表是无序的
// 	dummy := &ListNode{-1, nil}
// 	pre := dummy
// 	for h := head; h != nil; h = h.Next {
// 		if _, ok := hash[h.Val]; !ok {
// 			continue
// 		}
// 		pre.Next = h
// 		pre = pre.Next
// 	}
// 	pre.Next = nil

// 	return dummy.Next
// }

func deleteDuplicates(head *ListNode) *ListNode {
	dummy := &ListNode{-1, nil}
	pre := dummy
	dupVal := math.MaxInt32

	for h := head; h != nil; h = h.Next {
		if h.Val == dupVal {
			continue
		}
		if h.Next != nil && h.Val == h.Next.Val {
			dupVal = h.Val
			continue
		}
		pre.Next = h
		pre = pre.Next
	}
	pre.Next = nil
	return dummy.Next
}

// @lc code=end
