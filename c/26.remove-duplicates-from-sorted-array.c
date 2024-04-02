/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize)
{
    if (!nums || !numsSize) {
        return 0;
    }
    int last_index = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[last_index]) {
            nums[++last_index] = nums[i];
        }
    }
    return last_index + 1;
}
// @lc code=end

