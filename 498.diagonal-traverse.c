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
 * 1. index = row - 1或col-1或==0时转弯
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
    int i = 0, j = 0, index = 0, x = 0, y = 0;
    bool col_minus = false, plus = false;

    for (;i < max && j < max;) {
        if (i < col && j < row) {
            returnArray[index] = matrix[j][i];
            index++;
            if (index > (*returnSize)) {
                break;
            }
        }
        if (i % 2 == 0 && j == 0 ) {
            col_minus = true;
            i++;
            continue;
        }
        else if (j % 2 != 0 && i == 0) {
            col_minus = false;
            j++;
            continue;
        }else {
        }
        if (col_minus) {
            (i-1) < 0 ?  : (i--);
            j++;
        } else {
            i++;
            (j-1) < 0 ? : (j--);
        }
    }
    return returnArray;
}
// @lc code=end

