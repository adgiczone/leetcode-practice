/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numRows;
    *returnColumnSizes = (int *)malloc(numRows * sizeof(int));
    int **returnArray = (int**)malloc(numRows * sizeof(int *));

    for (int i = 0; i < numRows; i++) {
        returnArray[i] = (int *)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = (i + 1);
        if (i == 0) {
            returnArray[0][0] = 1;
            continue;
        }
        for (int j = 0; j < i + 1; j++) {
            returnArray[i][j] = (j == 0 || j == i) ? 1 : returnArray[i - 1][j] + returnArray[i - 1][j - 1];
        }
    }
    return returnArray;
}
// @lc code=end

