/*
 * @lc app=leetcode id=146 lang=golang
 *
 * [146] LRU Cache
 */

// @lc code=start
// O(1)的时间获取和添加，应该是哈希表+双向链表
type Node struct {
	Key  int
	Val  int
	Prev *Node
	Next *Node
	// 字节面试加了一个过期时间
	// get的时候如果时间过期了，旧删掉，然后返回-1，其他不用更改
	// createTime time.Du..
}

type LRUCache struct {
	Hash     map[int]*Node
	Head     *Node
	Capacity int
	CurSize  int
}

func Constructor(capacity int) LRUCache {
	head := &Node{math.MaxInt32, math.MaxInt32, nil, nil}
	hash := make(map[int]*Node)
	head.Next = head
	head.Prev = head.Next.Prev
	return LRUCache{
		Head:     head,
		Hash:     hash,
		Capacity: capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	node, ok := this.Hash[key]
	if !ok {
		return -1
	}

	prev := node.Prev
	next := node.Next
	headNext := this.Head.Next
	// 如果本来就在头部，就不用改了，直接返回
	if prev == this.Head {
		return node.Val
	}
	// 替换到头部，注意更改的顺序。
	prev.Next = next
	next.Prev = prev

	node.Prev = this.Head
	node.Next = headNext

	headNext.Prev = node
	this.Head.Next = node

	return node.Val
}

func (this *LRUCache) Put(key int, value int) {
	// 先查询，如果有就更新
	if this.Get(key) != -1 {
		this.Hash[key].Val = value
		return
	}
	// 判断是不是已经满了，满了删除最后一个
	if this.CurSize == this.Capacity {
		del := this.Head.Prev
		this.Head.Prev = del.Prev
		del.Prev.Next = this.Head
		delete(this.Hash, del.Key)
		this.CurSize -= 1
	}

	add := &Node{key, value, nil, nil}
	// 添加节点，注意操作的顺序
	headNext := this.Head.Next

	add.Prev = this.Head
	add.Next = headNext

	headNext.Prev = add
	this.Head.Next = add
	this.Hash[key] = add

	this.CurSize += 1
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end
