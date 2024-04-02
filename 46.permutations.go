/*
 * @lc app=leetcode id=46 lang=golang
 *
 * [46] Permutations
 */

// @lc code=start
func permute(nums []int) [][]int {
	// 返回的全排列数组
	res := make([][]int, 0)
	// 用来标识数字是否已经使用的数组
	used := make([]bool, len(nums))
	// 用来存放单个排列组合的数组
	tracks := make([]int, 0)
	getpermute(nums, used, tracks, &res)
	return res
}

func getpermute(nums []int, used []bool, tracks []int, res *[][]int) {
	// 如果tracks的长度满了，说明已经获取到了一个排列的内容
	if len(tracks) == len(nums) {
		temp := make([]int, len(tracks))
		copy(temp, tracks)
		(*res) = append((*res), temp)
	}

	for i := 0; i < len(nums); i++ {
		if used[i] {
			// 跳过已经选择的数字
			continue
		}
		// 把当前数字放到tracks里面
		tracks = append(tracks, nums[i])
		// 标识当前数字已经选中了
		used[i] = true
		getpermute(nums, used, tracks, res)
		// 递归返回说明已经有一个排列获取到了，取消当前数字的选择
		used[i] = false
		// tracks 也减少一位
		tracks = tracks[:len(tracks)-1]
	}
}

// @lc code=end
