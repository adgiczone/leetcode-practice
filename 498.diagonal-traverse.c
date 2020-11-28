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

int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (!matrixSize || !matrix || !matrixColSize) {
        return NULL;
    }

    int row = matrixSize;
    int col = (*matrixColSize);
    int total_size = row * col;
    printf("row:%d col:%d \r\n", row, col);

    if (!total_size) {
        return NULL;
    }
    int* returnArray = (int *)malloc(total_size * sizeof(int));
    if (!returnArray) {
        return NULL;
    }
    returnArray[0] = matrix[0][0];
    int i = 1, j = 0, index = 1;
    bool turn_flag = false, left_minus = true;

    while (index < total_size) {
        returnArray[index] = matrix[j][i];
        printf("returnArray[%d]:%d\n", index, returnArray[index]);
        printf("before i:%d j:%d turn_flag:%d left_minus:%d \r\n", i, j, turn_flag, left_minus);
        if (i == 0 || i == (row - 1) || j == 0 || j == (col-1)) {
            if (turn_flag) {
                if ((i == 0 || j == 0) && (i != (row - 1) && j != (col - 1))) {
                    printf("1");
                    (i > j) ? (i++) : (j++);
                } else /*if ((i == (row -1) || j == (col - 1)) && (i == 0 || j == 0))*/ {
                    printf("2");
                    (i > j) ? (j++) : (i++);
                }
                turn_flag = false;
            } else {
                turn_flag = true;
            }
            left_minus = (i > j) ? true : false;
        }
        printf("after i:%d j:%d turn_flag:%d left_minus:%d \r\n", i, j, turn_flag, left_minus);

        if (turn_flag == true) {
            if (left_minus) {
                i--;
                j++;
            } else {
                i++;
                j--;
            }
        }
        index++;
    }
    (*returnSize) = total_size;
    (*matrixColSize) = 1;
    return returnArray;
}
// @lc code=end

