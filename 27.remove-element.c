/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start


int removeElement(int* nums, int numsSize, int val)
{
    if (!nums || !numsSize) {
        return 0;
    }
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[j++] = nums[i];
        }
    }
    return j;
}
// @lc code=end

