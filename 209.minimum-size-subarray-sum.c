/*
 * @lc app=leetcode id=209 lang=c
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start

// sliding_window  O(n)
int minSubArrayLen(int s, int* nums, int numsSize)
{
    if (!nums || !numsSize) {
        return 0;
    }
    int head = 0, tail = 0;
    int sum = nums[0], number = __INT_MAX__;
    while (head <= tail && head < numsSize) {
        if (sum >= s){
            number = (number <= (tail - head)) ? number : (tail - head);
            sum -= nums[head++];
        } else {
            sum = (tail >= numsSize - 1) ? sum - nums[head++] : sum + nums[++tail];
        }
    }
    return (number == __INT_MAX__) ? 0 : number + 1;
}
// @lc code=end