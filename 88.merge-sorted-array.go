/*
 * @lc app=leetcode id=88 lang=golang
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
func merge(nums1 []int, m int, nums2 []int, n int) {
	// 因为num1后面是空的，所以从后往前，避免num1被覆盖
	p1, p2, s := m-1, n-1, len(nums1)-1
	for p1 >= 0 && p2 >= 0 {
		// nums1 > nums2 nums1后面放nums1的值，然后nums1往前走
		if nums1[p1] > nums2[p2] {
			nums1[s] = nums1[p1]
			p1--
		} else {
			nums1[s] = nums2[p2]
			p2--
		}
		s--
	}
	// 当出现n>m的情况，注意多的nums2的数值填到nums1里面去
	for p2 >= 0 {
		nums1[s] = nums2[p2]
		p2--
		s--
	}
}

// @lc code=end
