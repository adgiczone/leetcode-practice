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
    int max = (row > col) ? row : col;
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
        }
        printf ("i %d j %d %d %d %d\r\n", i, j, returnArray[index - 1], col_minus, plus);
        if (i % 2 == 0 && j == 0 && !plus) {
            printf ("in i\r\n");
            col_minus = true;
            plus = true;
            i++;
            continue;
        }
        else if (j % 2 != 0 && i == 0 && !plus) {
            printf ("in j\r\n");
            col_minus = false;
            plus = true;
            j++;
            continue;
        }else {
            plus = false;
        }
        if (col_minus) {
            (i-1) < 0 ?  : (i--);
            j++;
            if (j > )
        } else {
            i++;
            (j-1) < 0 ? : (j--);
        }
    }
    // while (index < (*returnSize)) {
    //     returnArray[index] = matrix[i][j];
    //     printf("returnArray[%d]:%d\n", index, returnArray[index]);
    //     printf("before i:%d j:%d turn_flag:%d left_minus:%d \r\n", i, j, turn_flag, left_minus);
    //     if (i == 0 || i == (col - 1) || j == 0 || j == (row-1)) {
    //         if (turn_flag) {
    //              printf("%d %d\r\n", (i == 0 || j == 0) && (i != (row - 1)) ? true: false, 
    //                                 (i == 0 || j == 0) && (j != (col - 1)) ? true: false);
    //             if (((i == 0 || j == 0) && (i != (row - 1))) && (j != (col - 1))) {
    //                 (i > j) ? (i++) : (j++);
    //             } else {
    //                 (i > j) ? (j++) : (i++);
    //             }

    //             if ((i >= row) || (j >= col)) {
    //             }else {
    //                 turn_flag = false;
    //             }
    //         } else {
    //             turn_flag = true;
    //         }

    //         left_minus = (i > j) ? true : false;
    //     }

    //     if (turn_flag == true) {
    //         if (left_minus) {
    //             i-1 < 0 ?: i--;
    //             j+1 >= col ?: j++;
    //         } else {
    //             j-1 < 0 ?: j--;
    //             i+1 >= row ?: i++;
    //         }
    //     }

    //     printf("after i:%d j:%d turn_flag:%d left_minus:%d \r\n", i, j, turn_flag, left_minus);
    //     index++;
    // }
    return returnArray;
}
// @lc code=end

