/*
 * @lc app=leetcode id=90 lang=golang
 *
 * [90] Subsets II
 */

// @lc code=start
func subsetsWithDup(nums []int) [][]int {
	// 和subsets比多了重复元素，这样的话最好先排序，
	// 然后对比上一个元素，如果相同就跳过
	res := make([][]int, 0)
	track := make([]int, 0)

	sort.Ints(nums)
	var backtrack func(start int)
	backtrack = func(start int) {
		tmp := make([]int, len(track))
		copy(tmp, track)
		res = append(res, tmp)

		for i := start; i < len(nums); i++ {
			// 这个无效，因为这个只会阻止重复的元素进入track，
			// 不会阻止track中重复的元素
			// if len(track) > 0 && nums[i] == track[len(track)-1] {
			// 	continue
			// }
			if i > start && nums[i] == nums[i-1] {
				continue
			}
			track = append(track, nums[i])
			backtrack(i + 1)
			track = track[:len(track)-1]
		}
	}
	backtrack(0)
	return res
}

// @lc code=end

