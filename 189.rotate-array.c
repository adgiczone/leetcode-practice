/*
 * @lc app=leetcode id=189 lang=c
 *
 * [189] Rotate Array
 */

// @lc code=start


void rotate(int* nums, int numsSize, int k)
{
    if (!nums || !numsSize || !k) {
        return;
    }
    for (int i = 0; i < k; i++) {
        int temp = nums[numsSize - 1];
        memmove(nums + 1, nums, sizeof(int) * (numsSize - 1));
        nums[0] = temp;
    }
}
// @lc code=end

