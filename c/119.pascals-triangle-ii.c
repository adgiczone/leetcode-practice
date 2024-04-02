/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    if (!returnSize) {
        return NULL;
    }
    int i = 0, j = 0;
    int *return_array = (int *)malloc((rowIndex + 1) * sizeof(int));
    *returnSize = rowIndex + 1;
    if (!return_array)
        return NULL;
    for (i = 0; i <= rowIndex + 1; i++) {
        return_array[0] = 1;
        for (j = i - 1; j > 0; j--) {
            return_array[j] += return_array[j - 1];
        }
        (i - 1 <= 0) ?: (return_array[i - 1] = 1);
    }
    return return_array;
}
// @lc code=end

