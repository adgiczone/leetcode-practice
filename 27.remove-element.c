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
    int head = 0, tail = numsSize - 1;
    while (head <= tail) {
        if (nums[head] == val) {
            while (nums[tail] == val && (tail > head) && (tail > 0)) {
                tail--;
            }
            nums[head] = nums[tail];
            if ((--tail) == 0) {
                break;
            }
        }
        head++;
    }
    if ((tail > 0) && nums[tail] == val) {
        tail = tail - 1;
    }
    return (tail == 0 && nums[tail] == val) ? tail : tail + 1;
}
// @lc code=end

