/*
 * @lc app=leetcode id=498 lang=c
 *
 * [498] Diagonal Traverse
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * @note
 * 1. index = row - 1或 col - 1或==0时转弯
 * 2. 基于1, 位数较大的index + 1
 */

int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    if (!matrixSize || !matrix || !matrixColSize) {
        (*returnSize) = 0;
        return NULL;
    }

    int row = matrixSize;
    int col = (*matrixColSize);
    *returnSize = row * col;
    printf("row:%d col:%d \r\n", row, col);
    int max = row + col;//(row > col) ? row : col;
    int* returnArray = (int *)malloc((*returnSize) * sizeof(int));
    if (!returnArray) {
        (*returnSize) = 0;
        return NULL;
    }
    int i = 0, j = 0, index = 0, extra_i = 0, extra_j = 0, x = 0, y = 0;
    bool col_minus = false;

    while (index < (*returnSize)) {
        printf("matrix[%d+%d][%d+%d]", j, extra_i, i, extra_j);
        j += extra_i;
        i += extra_j;
        returnArray[index++] = matrix[j][i];
        printf(" = array[%d]: %d\r\n", index-1, returnArray[index-1]);
        if ((i % 2 == 0 && j == 0 && !extra_i) || (i == (col - 1) && extra_j) ) {
            extra_i = 0;
            extra_j = 0;
            col_minus = true;
            (i+1) >= col ? extra_i = 1 : i++;
            continue;
        }
        else if ((j % 2 != 0 && i == 0 && !extra_j) || (j == (row - 1) && extra_i)) {
            extra_i = 0;
            extra_j = 0;
            col_minus = false;
            (j+1) >= row ? extra_j = 1 : j++;
            continue;
        }
        extra_i = 0;
        extra_j = 0;

        printf("------------col_minus:%d\r\n", col_minus);
        if (col_minus) {
            if ((j+1) >= row) {
                extra_j = 1;
            } else {
                (i-1) < 0 ?  : (i--);
                j++;
            }
        } else {
            if ((i+1) >= col) {
                extra_i = 1;
            } else {
                i++;
                (j-1) < 0 ? : (j--);
            }
        }
    }
    return returnArray;
}
// @lc code=end
